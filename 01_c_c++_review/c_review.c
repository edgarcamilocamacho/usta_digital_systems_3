#include "stdio.h"

int main(int argc, char** argv){

    int x = 10;
    int y = 20;

    int z, a;

    a = (z = (x + 5) * y) - 25;

    printf("z=%d\n", z);
    printf("a=%d\n", a);

    // if(x){
    //     printf("SI\n");
    // }else{
    //     printf("NO\n");
    // }

    // for(i=0; i<10; i++){

    // }

    return 0;
}