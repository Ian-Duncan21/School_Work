#include <stdio.h>
#include <stdlib.h>
#include "Executor.h"

int random_in_range(int lower_bound, int upper_bound){
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}

float get_running_ratio(){
    float ratio = 0.0;
    int maxPrimeCount = 0;
    int maxCountIteration = 0;
    float runningRatio = 0.0; 
    int totalIterations = random_in_range(50, 100); //provide number of iterations
    printf("[Executor]: Number of iterations is: %d\n", totalIterations);
    
    for(int i = 1; i < totalIterations + 1; i++){  //loop through total # of iterations provided by seed
        int elemCount = random_in_range(100, 150);
        int *arrPt;
        arrPt = (int *)malloc(sizeof(int)*elemCount); //allocate each array with different count of elements
        
        for(int j = 0; j < elemCount; j++){ //Populate the arrays with elements between 50 and 199 inclusive
            arrPt[j] = random_in_range(50, 200);
        }
        
        if(get_prime_count(arrPt, elemCount) > maxPrimeCount){
            maxPrimeCount = get_prime_count(arrPt, elemCount);
            maxCountIteration = i;
        }
        
        int primeCount = get_prime_count(arrPt, elemCount);
        int nonPrime = elemCount - primeCount;
        ratio = (float)primeCount / nonPrime;
        runningRatio = ratio + runningRatio;
       
        //free(arrPt);
        free(arrPt);
    }
    
    //runningRatio = ratio + runningRatio;
    printf("[Executor]: Iteration with maximum prime count is: %d\n", maxCountIteration);
    return runningRatio / totalIterations;
    
}

int get_prime_count(int *array, int arraySize){
    int count = 0;
    for(int i = 1; i < arraySize; i++){
        int currentElement = array[i];
        int temp = 1;
        
        for(int j = 2; j <= currentElement / 2; ++j){
            if(currentElement % j == 0){
                temp = 0;
                break;
            }
        }
        
        if(temp == 1){
            count++;
        }
        //temp = 0;
    }
    
    return count;
}


