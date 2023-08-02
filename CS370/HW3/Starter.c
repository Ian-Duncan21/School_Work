#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#define READ 0
#define WRITE 1

    int main(int argc, char* argv[]) {  
        if(argc != 2){ //check for correct number of arguments
            printf("Provide one argument\n");
            exit(1);
        }
        
        int fd[2];
        char buf[256]; //character buffer
        pid_t myPid = getpid(); //parent pid
        if(pipe(fd) == -1){
            fprintf(stderr, "Pipe Failed.\n");
            return 1;
        }
        sprintf(buf, "%d", fd[1]);
            
        pid_t pid = fork(); //fork process and check for failure
        if(pid < 0){
            printf("Fork Failed\n");
            return 1;
        }
        if(pid == 0){
            close(fd[READ]); //close read end
            execlp("./Reader", "Reader",  argv[1], buf, NULL); 
        } 
        else{
            int readerStatus;
            pid = wait(&readerStatus);
                if (WIFEXITED(readerStatus)){
                    close(fd[WRITE]);
                    read(fd[READ], buf, 10);
                    close(fd[READ]);
                }
                else {
                    printf("Reader was not stopped\n");
                    return 1;
                }
        }
        
        int inputs = atoi(buf);
            
        printf("Starter[%d]: contents read from the read end pipe: %d\n", myPid, inputs);
        
        int primes = 0;
        for(int x = 2; x <= primes; x++){
            int p = 0;
            for(int i = 1; i <= x; i++){
                if(x % i == 0){
                    p++;
                }
            }
            if(p == 2 && x > primes){
                primes = x;
            }
        }
            
        char* lucasName = "SHM_Lucas";
        char* hexagonalName = "SHM_HexagonalSeries";
        char* harmonicName = "SHM_HarmoicSeries";
            
        //open the shared memory
        int shmLucas = shm_open(lucasName, O_CREAT | O_RDWR, 0666);
        int shmHexagonal = shm_open(hexagonalName, O_CREAT | O_RDWR, 0666);
        int shmHarmonic = shm_open(harmonicName, O_CREAT | O_RDWR, 0666);
        
        if(lucasName < 0 || hexagonalName < 0 || harmonicName < 0){
            printf("SHM Failed\n");
            return 1;
        }
            
        ftruncate(shmLucas, 32); //truncate to 32 bytes
        ftruncate(shmHexagonal, 32);
        ftruncate(shmHarmonic, 32);
            
        int *lucasPtr = mmap(0, 32, PROT_READ, MAP_SHARED, shmLucas, 0); //mmap pointers
        int *hexagonalPtr = mmap(0, 32, PROT_READ, MAP_SHARED, shmHexagonal, 0);
        int *harmonicPtr = mmap(0, 32, PROT_READ, MAP_SHARED, shmHarmonic, 0);
            
        printf("Starter[%d] : Created Shared memory \"%s\" with FD: %d\n", myPid, lucasName, shmLucas);
        printf("Starter[%d] : Created Shared memory \"%s\" with FD: %d\n", myPid, hexagonalName, shmHexagonal);
        printf("Starter[%d] : Created Shared memory \"%s\" with FD: %d\n", myPid, harmonicName, shmHarmonic);
            
        char* names[3]; //command and names used to loop through programs
        names[0] = lucasName;
        names[1] = hexagonalName;
        names[2] = harmonicName;
            
        char* command[3];
        command[0] = "./Lucas";
        command[1] = "./HexagonalSeries";
        command[2] = "./HarmonicSeries";
        pid_t* pids = (pid_t*)malloc(3 * sizeof(pid_t));  //store PID for later
            
        for(int i = 0; i < 3; i++) { //run programs
            pid_t pid = fork();
            if(pid < 0) {
                return -1;
            }
            if(pid == 0) {
                execlp(command[i], command[i], names[i], buf, NULL);
            }
            if(pid > 0) {
                pids[i] = pid;
            }
        }
        

        for(int i = 0; i < 3; i++) { //wait for all to finish
            int status;
            waitpid(pids[i], &status, 0);
        }
        free(pids);
            
        int lucasRet = *lucasPtr; //retrieve values from shared memory
        int hexagonalRet = *hexagonalPtr;
        int harmonicRet = *harmonicPtr;
            
        printf("Starter[%d]: Lucas last number: %d\n", myPid, lucasRet); 
        printf("Starter[%d]: Hexagonal Series last number: %d\n", myPid, hexagonalRet);
        printf("Starter[%d]: Harmonic Series last number: %d\n", myPid, harmonicRet);
            
        //Unlink memory
        if((shm_unlink(lucasName) == -1) || (shm_unlink(hexagonalName) == -1) || (shm_unlink(harmonicName) == -1)){
            return -1;
        }
        munmap(lucasPtr, 32);
        munmap(hexagonalPtr, 32);
        munmap(harmonicPtr, 32);
        
        return 0;
    }
