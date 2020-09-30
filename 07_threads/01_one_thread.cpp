#include <iostream>
#include <sstream>
#include <pthread.h>
#include <cmath>

using namespace std;

double sum; // Variable compartida por todos los hilos
void *runner(void *param); // Prototipo de funcion a ser ejecutada por hilo

//un_hilo num_sumatoria
int main(int argc, char *argv[]){
	pthread_t tid; //id del hilo
	pthread_attr_t attr; //atributos del hilo

	//inicializar atributos de scheduling del hilo por defecto
	pthread_attr_init(&attr);

	//crear hilo
	//pthread_create(id hilo, atributos hilo, void* rutina hilo, void* argumentos rutina)
	pthread_create(&tid, &attr, runner, argv[1]);

	// creacion sincrona: esperar a que hilo tid finalice
	// pthread_join(id hilo, retorno de exit del hilo)
	pthread_join(tid, NULL);

	//Mostrar por consola el resultado de la operación del hilo
	cout << "sum = " << sum << "\n";
}

//funcion del hilo
void *runner(void *param){
	int i, N;
	stringstream ss((char*)param);
	ss >> N;
	sum = 0; //inicializa variable global
	for(i=1; i<=N; i++){
		sum += sin((double)i);
	}
	pthread_exit(0);
}