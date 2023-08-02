    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>

    int lucas(int n){ //recursion to find lucas numbers
        if (n == 0){
            return 2;
        }
        if (n == 1){
            return 1;
        }
        
        return lucas(n - 1) + lucas(n - 2);
    }

    int main(int argc, char *argv[]) {
       
        if(argc != 2){ //check for correct number of arguments
            printf("Provide one argument\n");
            exit(1);
        }
        
        int input = atoi(argv[1]); //convert args to ints
        int lucasSum = 0;
        pid_t pid = getpid();
        
        for(int x = 0; x < input; x++){ //store sum of lucas numbers
            lucasSum = lucasSum + lucas(x);
        }
        
        printf("[Lucas] [%d]: The sum of the first %d numbers of the Lucas series is %d\n", pid, input, lucasSum);
        printf("[Lucas] [%d]: The nth number in the lucas series is %d\n", pid, input);
        
            if(lucasSum > 50){ //print n if sum is > 50
                return input;
            }
            else if(lucasSum < 50){ //print sum if sum is < 50
                return lucasSum;
            }
            
        
    }
