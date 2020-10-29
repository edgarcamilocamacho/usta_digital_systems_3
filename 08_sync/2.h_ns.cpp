#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define NITER 1000000

int cnt = 0;
sem_t semaphore;

void *count(void * a){
    int i, tmp;
    for(i = 0; i < NITER; i++)
        cnt += 1;    
}

int main(){
	pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, count, NULL);
    pthread_create(&tid2, NULL, count, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    if (cnt < 2 * NITER) 
    	cout << "ERROR! cnt = " << cnt << " pero debería ser " << 2*NITER << endl;
    else
    	cout << "OK! cnt = " << cnt << endl;
           
    pthread_exit(NULL);
}