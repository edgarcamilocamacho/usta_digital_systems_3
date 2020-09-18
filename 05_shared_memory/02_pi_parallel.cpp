#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/types.h>

pid_t *pidChildren;
int n, id;
void *smem;

int find_child(pid_t pid){
    for(int i=0; i<n; i++){
        if(pid == pidChildren[i])
            return i;
    }
    return -1;
}

int main(int argc, char** argv)
{
    int i, numInters;

    if(argc==3){
        numInters = atoi(argv[1]);
        n = atoi(argv[2]);
        printf("[P] Iniciando con %d iteraciones y %d procesos.\n", numInters, n);
    }else if(argc==1){
        numInters = 1000000000;
        n = 4;
        printf("[P] Iniciando con %d iteraciones y %d procesos.\n", numInters, n);
    }else{
        printf("[P] Error. Número incorrecto de parámetros.\n");
        return 1;
    }

    if(n>32) n=32;

    smem = mmap(NULL, n*sizeof(float), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    printf("[n] Creando %d hijos.\n\n", n);
    pidChildren = new pid_t[n];

    for(i=0; i<n; i++){
        pidChildren[i] = fork();
        if(pidChildren[i] == 0){
            id = i;
            printf("[C%d] Hijo creado.\n", id);
            break;
        }
    }

    // Tengo n hijos y el padre

    if(i==n){ // Padre
        double totalPi = 0.0;
        printf("[P] Esperando finalización de hijos.\n");
        for(i=0; i<n; i++){
            int status;
            pid_t wpid = wait(&status);
            int wid = find_child(wpid);
            printf("[P] Finalizado el hijo %d\n", wid);
        }
        for(i=0; i<n; i++){
            totalPi += *(((double*)smem)+i);
        }
        totalPi *= 4.0;
        printf("[P] Pi = %.30f\n", totalPi);
        munmap(smem, n*sizeof(float));
        printf("[P] Fin de proceso padre.\n");
        return 0;
    }else{ // Hijos
        double calcPi = 0.0;
        int start = (numInters/n)*id;
        int stop = (numInters/n)*(id+1);
        for(i=start; i<stop; i++){
            calcPi += 1.0/((double)(i*4+1));
            calcPi -= 1.0/((double)(i*4+3));
        }
        printf("[C%d] calcPi = %.30f\n", id, calcPi);
        // calcPi tiene la suma parcial
        *(((double*)smem)+id) = calcPi;
        return 0;
    }

}