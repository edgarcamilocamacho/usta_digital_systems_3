#include <stdio.h>
#include <stdlib.h>

struct Complex{
    double real;
    double imag;
};

int compare1(Complex *a, Complex *b){
    return (a->real > b->real);
}

int compare2(Complex *a, Complex *b){
    return (a->imag > b->imag);
}

int main(int argc, int argv){
    Complex x1; // 1.2+0.7j
    x1.real = 1.2;
    x1.imag = 0.7;
    Complex x2; // 0.5+7.1j
    x2.real = 0.5;
    x2.imag = 7.1;

    int (*compare_pointer)(Complex*, Complex*);
    compare_pointer = &compare2;

    ///////////////////////////////

    if((*compare_pointer)(&x1, &x2)){
        printf("x1 es mayor que x2\n");
    }else{
        printf("x1 es menor que x2\n");
    }

    return 0;
}