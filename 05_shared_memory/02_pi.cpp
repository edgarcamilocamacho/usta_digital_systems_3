#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    int i, numInters;

    if(argc==2){
        numInters = atoi(argv[1]);
    }else if(argc==1){
        numInters = 1000000000;
    }else{
        printf("[P] Error. Número incorrecto de parámetros.\n");
        return 1;
    }

    double calcPi = 0.0;

    for(i=0; i<numInters; i++){
        calcPi += 1.0/((double)(i*4+1));
        calcPi -= 1.0/((double)(i*4+3));
    }

    calcPi *= 4.0;
    printf("Pi = %.30f\n",calcPi);
}