    #include <stdio.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        pid_t myPid = getpid();
        printf("[Generator] [%d]: Waiting for the child process %d\n", myPid, myPid);
        
        FILE * fp = fopen(argv[1], "r"); //open the file we are reading from in read mode
        
        if(fp == NULL){ //Cannot open file 
            printf("Error opening file\n");
            exit(1);
        }
        
        char currentLine[100]; //buffer for the arguments
        
        while(fgets(currentLine, 100, fp) != NULL){
            const char *execNames[] = {"./Lucas", "./HexagonalSeries", "./HarmonicSeries"};
            int returnValue[3];
            
            for(int x = 0; x < 3; x++){ //loop through all child processes 
                
                pid_t pid = fork(); //fork the process
        
                if(pid < 0){
                    printf("Fork Failed\n");
                    exit(1);
                }
                else if(pid == 0){
                    execlp(execNames[x], execNames[x], currentLine, NULL);
                }
                else{
                    int status;
                    pid = wait(&status);
                    
                    if(WIFEXITED(status)){
                        printf("[Generator] [%d]: The child process %d returned %d\n", myPid, pid, WEXITSTATUS(status));
                        sprintf(currentLine, "%d", WEXITSTATUS(status));//Store previous process output
                        returnValue[x] = WEXITSTATUS(status); //Stores return value of process to be printed later
                    }
                    else{
                        exit(1);
                    }
                }
            }
            printf("[Generator] [%d]: The lucas child process returned %d\n", myPid, returnValue[0]);
            printf("[Generator] [%d]: The Hexagonal child process returned %d\n", myPid, returnValue[1]);
            printf("[Generator] [%d]: The sum of the first n Harmonic numbers is %d\n", myPid, returnValue[2]);
        }
        fclose(fp); //close file
        return 0;
    }
