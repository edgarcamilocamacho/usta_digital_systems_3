#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
using namespace std;

#define N 10

const int SIZE = 4096;
const char *name_shm = "sh_mem";
const char *name_sem = "smp";


int main(){
	int shm_fd = shm_open(name_shm, O_CREAT | O_RDWR, 0666);	
	ftruncate(shm_fd, SIZE);	
	pid_t pid = fork();	
	
	if(pid < 0)
	{
		cerr << "Can't create child process" << endl;
		return 1;
	}
	if(pid == 0)
	{
		cout << "comienza proceso hijo" << endl;
		usleep(1000*1000);
		sem_t *sem_id = sem_open(name_sem, O_CREAT, 0600, 0);
		void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
		for(int i=0; i<N; i++){			
			*(((int*)ptr)+(i+1)) = i*2;
		}
		cout << "proceso hijo entrega semaforo ... " << endl;
		sem_post(sem_id);

	}
	else{
		//wait(NULL);
		sem_t *sem_id = sem_open(name_sem, O_CREAT, 0600, 0);
		sem_wait(sem_id);
		cout << "comienza proceso padre" << endl;
		void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
		for(int i=0; i<N; i++){			
			cout << *(((int*)ptr)+(i+1)) << endl;
		}
		shm_unlink(name_shm);
		sem_post(sem_id);
		sem_close(sem_id);
		sem_unlink(name_sem);
		cout << "proceso padre entrega y elimina semaforo ..." << endl;
	}
	return 0;
}
