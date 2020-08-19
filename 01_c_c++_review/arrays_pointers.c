#include "stdio.h"

int x = 50;
int y = 25;
int *px;

int arr[5] = {2,5,4,8,6};

int a = 80;

char s1[] = "Cualquier cosa";

int main(int argc, char** argv){

    int i=0;

    printf("argc=%d\n", argc);

    //////////////////

    // px=0x00000001;
    // printf("*px=%d\n", *px);

    ////////////

    // for(i=0; i<6; i++){
    //     printf("arr[%d] = %d\n", i, arr[i]);
    // }

    /////////////////////////////

    // printf("arr[0]=%d\n", arr[0]);
    // printf("*(arr+0)=%d\n", *(arr+0));

    // *(arr+2) = 46;

    // printf("arr[2]=%d\n", arr[2]);
    // printf("*(arr+2)=%d\n", *(arr+2));

    ////////////////////

    // printf("arr[0]=%d\n", arr[0]);
    // printf("arr[1]=%d\n", arr[1]);

    // printf("arr=0x%u\n", arr);

    // printf("&arr[0]=0x%u\n", &arr[0]);
    // printf("&arr[1]=0x%u\n", &arr[1]);

    ////////////////

    // char *pc = &x;
    // printf("pc=%d\n", pc);
    // pc++;
    // printf("pc=%d\n", pc);

    /////////////////////

    // px = &x + 2;

    // printf("x=%d\n", x);
    // printf("sizeof(x)=%d\n", sizeof(x));
    // printf("px=0x%x\n", px);

    // printf("&y=0x%x\n", &y);

    // printf("%d\n", arr);

    return 0;
}