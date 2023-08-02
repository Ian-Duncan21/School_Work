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
            printf("Provide two arguments\n");
            exit(1);
        }
        
        pid_t pid = getpid();
        int SHM_HexagonalSeries = shm_open(argv[1], O_RDWR, 0666);
        if(SHM_HexagonalSeries < 0){
            printf("Failed\n");
            return -1;
        }
        
        int *hexagonalPtr = mmap(0, 32, PROT_READ | PROT_WRITE, MAP_SHARED, SHM_HexagonalSeries, 0);
        
        int hex(int x){ //find hexagonal series numbers
            return x*(2*x - 1);
        }
        
        int input = atoi(argv[2]); //convert args to ints
        int hexSum = 0;
        
        printf("[HexagonalSeries] [%d]: The first %d of the hexagonal series are :\n", pid, input);
        
        for(int i = 0; i < input; i++){
            printf("%d ", hex(i));
        }
        
        printf("\n");
        
        for(int x = 0; x <= input; x++){ //get sum of n number of ints
            hexSum = hexSum + hex(x);
        }
        
        printf("[HexagonalSeries] [%d]: The %dth number in the Hexagonal series is :%d\n", pid, input, hex(input));
        printf("[HexagonalSeries] [%d]: The sum of first %d hexagonal numbers is:%d\n", pid, input, hexSum);
        
            if(hexSum > 100){ //return n if sum is > 100
                *hexagonalPtr = hex(input);
            }
            else if(hexSum < 100){ //return the sum if sum is < 100
                *hexagonalPtr = hexSum;
            }
        
        munmap(hexagonalPtr, 32);
        close(SHM_HexagonalSeries);
        shm_unlink(argv[1]);
        return 0;
        
    }
