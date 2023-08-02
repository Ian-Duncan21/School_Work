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

    int lucas(int n){ //recursion to find lucas numbers
        if (n == 0){
            return 2;
        }
        if (n == 1){
            return 1;
        }
        
        return lucas(n - 1) + lucas(n - 2);
    }

    int main(int argc, char** argv) {
       
        if(argc != 3){ //check for correct number of arguments
            printf("Provide one argument\n");
            exit(1);
        }
        
        pid_t pid = getpid();
        int SHM_Lucas = shm_open(argv[1], O_RDWR, 0666);
        if(SHM_Lucas < 0){
            printf("Failed\n");
            return -1;
        }
        
        int *lucasPtr = mmap(0, 32, PROT_READ | PROT_WRITE, MAP_SHARED, SHM_Lucas, 0);
        
        int input = atoi(argv[2]); //convert args to ints
        int lucasSum = 0;
        
        printf("[Lucas] [%d]: The first %d of the Lucas series are :\n", pid, input);
        
        for(int i = 0; i < input; i++){
            printf("%d ", lucas(i));
        }
        
        for(int x = 0; x < input; x++){ //store sum of lucas numbers
            lucasSum = lucasSum + lucas(x);
        }
        
        printf("[Lucas] [%d]: The nth number in the lucas series is %d\n", pid, input);
        printf("[Lucas] [%d]: The sum of the first %d numbers of the Lucas series is %d\n", pid, input, lucasSum);
        
            if(lucasSum > 50){ //print n if sum is > 50
                *lucasPtr =  lucas(input);
            }
            else if(lucasSum < 50){ //print sum if sum is < 50
                *lucasPtr = lucasSum;
            }
        
        munmap(lucasPtr, 32);
        close(SHM_Lucas);
        shm_unlink(argv[1]);
        return 0;
        
    }
