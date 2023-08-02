    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>
    
    int main(int argc, char *argv[]) {
        if(argc != 2){ //check for correct number of arguments
            printf("Provide one argument\n");
            exit(1);
        }
        
        
        float input = atof(argv[1]); //convert args to float
        float sum = 0.0;
        pid_t pid = getpid();
        int input2 = atoi(argv[1]);//convert arg to int also so I can use int and float in the output
        
        for(int x = 1; x <= input; x++){ //find Harmonic numbers
            sum = sum + (1.0/x);
        }
        
        printf("[HarmonicSeries] [%d]: The sum of the first %d numbers of the harmonic series is %f\n", pid, input2, sum);
        return (int)sum;
        
    }
