#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t    mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t    mutex2 = PTHREAD_MUTEX_INITIALIZER;
 
void *ThreadA(void *parm)
{
    // Creates deadlock problem
    pthread_mutex_lock(&mutex1);
    cout << "Thread 1" << endl;
    pthread_mutex_lock(&mutex2);
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
}
 
void *ThreadB(void *parm)
{
    // Creates deadlock problem
    pthread_mutex_lock(&mutex1);
    cout << "Thread 2" << endl;
    pthread_mutex_lock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
}
 
 
int main()
{
    pthread_t   t1, t2;
    pthread_attr_t  atr;
    pthread_attr_init(&atr);
    pthread_create(&t1, &atr, ThreadA, NULL);
    pthread_create(&t2, &atr, ThreadB, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 	pthread_mutex_destroy(&mutex1);
 	pthread_mutex_destroy(&mutex2);
    cout << "----------------" << endl;
    return 0;
}
