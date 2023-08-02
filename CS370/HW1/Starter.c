#include "Executor.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2 ){
        printf("Error: Enter 1 Argument");
        return 0; 
    }
    
    int seed = atoi(argv[1]); //convert arg to int
    srand(seed); //generate random seed
    printf("[Starter]: With seed: %d\n", seed);
    
    float running_ratio = get_running_ratio();
    printf("[Starter]: Running ratio: %.6f\n", running_ratio);
    
    return 0;
    
}
