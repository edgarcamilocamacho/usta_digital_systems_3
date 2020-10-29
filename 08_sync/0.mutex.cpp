//g++ -o 0.mutex 0.mutex.cpp -pthread
#include <pthread.h>
#include <iostream>
using namespace std;

#define THREADS 16
pthread_mutex_t    mutex = PTHREAD_MUTEX_INITIALIZER;
int id = 0;


void *threadfunc(void *parm){    
    pthread_mutex_lock(&mutex); //Adquirir
    id ++; //*((int *)parm);
    cout << "Thread " << pthread_self() << "\t" << id << endl;
    pthread_mutex_unlock(&mutex); //Liberar
    return NULL;
}

int main(){
    pthread_t   arr_threads[THREADS];
    pthread_attr_t  atr;
    int i;
    pthread_attr_init(&atr);
    //pthread_attr_setdetachstate(&atr, PTHREAD_CREATE_JOINABLE);
    for(i=0; i<THREADS; i++){
        pthread_create(&arr_threads[i], &atr, threadfunc, &i);
    }
    for(i=0; i<THREADS; i++){
        pthread_join(arr_threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    cout << "----------------" << endl;
 }

