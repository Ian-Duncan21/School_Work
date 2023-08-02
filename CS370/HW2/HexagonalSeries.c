    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        if(argc != 2){ //check for correct number of arguments
            printf("Provide one argument\n");
            exit(1);
        }
        
        int hex(int x){ //find hexagonal series numbers
            return x*(2*x - 1);
        }
        
        int input = atoi(argv[1]); //convert args to ints
        int hexSum = 0;
        pid_t pid = getpid();
        
        for(int x = 0; x <= input; x++){ //get sum of n number of ints
            hexSum = hexSum + hex(x);
        }
        
        printf("[HexagonalSeries] [%d]: The sum of first %d hexagonal numbers is:%d\n", pid, input, hexSum);
        printf("[HexagonalSeries] [%d]: The nth number in the Hexagonal series is %d\n", pid, input);
        
            if(hexSum > 100){ //return n if sum is > 100
                return input;
            }
            else if(hexSum < 100){ //return the sum if sum is < 100
                return hexSum;
            }
        
    }
