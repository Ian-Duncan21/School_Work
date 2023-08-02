#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    int x = atoi(argv[2]);
    
    FILE * fp = fopen(argv[1], "r"); //open the file we are reading from in read mode
    if(fp == NULL){
        printf("Could not open file\n");
        return 1;
    }
    
    char buf[256];
    int runningSum = 0;
    while(fgets(buf, 256, fp)){
        runningSum = runningSum + atoi(buf);
    }
    sprintf(buf, "%d", runningSum);
    
    write(x, buf, (strlen(buf) + 1));
    close(x);
    fclose(fp);
    
    return 0;
}
