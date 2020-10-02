#include <iostream>
#include <sstream>
#include <pthread.h>
#include <cmath>
#include <stdio.h>

using namespace std;

typedef struct {
    int lw;
    int up;
    int id;
} arg_thread;

double sum = 0.0; // Variable compartida por todos los hilos
double *sum_vector; // Vector para sumas parciales
void *runner(void *data); // Funcion a ser ejecutada por hilo

//./N_hilos num_sumatoria num_hilos
int main(int argc, char *argv[]){
	int numThreads, N;
	stringstream ss((char*)argv[2]);
	ss >> numThreads;
	stringstream ss2((char*)argv[1]);
	ss2 >> N;
	sum_vector = new double[numThreads];

    if(numThreads>32) numThreads=32;

	// std::cout << "numThreads:" << numThreads << std::endl;

	pthread_t threads[numThreads];
	pthread_attr_t attr[numThreads];
	arg_thread arguments[numThreads];

	for(int i=0; i<numThreads; i++){
		arguments[i].lw = int(i*((double)N/numThreads))+1;      // 0    250  500  750
		arguments[i].up = int((i+1)*((double)N/numThreads));    // 250  500  750  1000
		arguments[i].id = i;
		pthread_attr_init(&attr[i]);
		pthread_create(&threads[i], &attr[i], runner, &arguments[i]);
	}
	for(int i=0; i<numThreads; i++){
		pthread_join(threads[i], NULL);
		sum += sum_vector[i];
	}
	//Mostrar por consola el resultado de la operación del hilo
	cout << "sum = " << sum << "\n";
}

//funcion del hilo
void *runner(void *data){
	int lw, up, id;
	lw = ((arg_thread*)data)->lw;
	up = ((arg_thread*)data)->up;
	id = ((arg_thread*)data)->id;
	printf("id:%d, lw:%d, up:%d\n", id, lw, up);
	for(int i=lw; i<=up; i++){
		sum_vector[id] += sin((double)i);
	}
	pthread_exit(0);
}