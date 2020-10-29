//g++ -o 0.sin_mutex 0.sin_mutex.cpp -pthread
#include <pthread.h>
#include <iostream>
using namespace std;

#define THREADS 16
int id = 0;

void *threadfunc(void *parm){    
    id ++; //*((int *)parm);
    cout << "Thread " << pthread_self() << "\t" << id << endl;
    return NULL;
}

int main(){
    pthread_t       arr_threads[THREADS];
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
    cout << "----------------" << endl;
 }

