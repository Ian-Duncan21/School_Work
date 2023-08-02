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
    
    int main(int argc, char *argv[]) {
        if(argc != 3){ //check for correct number of arguments
            printf("Provide one argument\n");
            exit(1);
        }
        
        pid_t pid = getpid(); //creates process identifier
        int SHM_HarmonicSeries = shm_open(argv[1], O_RDWR, 0666); //open up shared memory
        if(SHM_HarmonicSeries < 0){ //makes sure memory link did not fail
            printf("Shared memory failed\n");
            return 1;
        }
        int *harmonicPtr = mmap(0, 32, PROT_READ | PROT_WRITE, MAP_SHARED, SHM_HarmonicSeries, 0); //create a map to map a ptr to shared memory
        
        float input = atof(argv[2]); //convert args to float
        
        printf("[HarmonicSeries] [%d]: The first %d of the harmonic series are :\n", pid, atoi(argv[2]));
        
        for(int x = 0; x < input; x++){
            printf("%f ", 1.0 / x);
        }
        printf("\n");
        
        float sum = 0.0;
        float num;
        //int input2 = atoi(argv[2]);//convert arg to int also so I can use int and float in the output
        
        for(int x = 1; x <= input; x++){ //find Harmonic numbers
            sum = sum + (1.0/x);
            if(x == num){
                num = (1.0 / x);
            }
        }
        
        printf("[HarmonicSeries] [%d]: The %dth value in the harmonic series is %f\n", pid, atoi(argv[2]), num);
        printf("[HarmonicSeries] [%d]: The sum of the first %d numbers of the harmonic series is %f\n", pid, atoi(argv[2]), sum);
        
        *harmonicPtr = (int)sum;
        
        munmap(harmonicPtr, 32);
        close(SHM_HarmonicSeries);
        shm_unlink(argv[1]);
        return 0;
    }
