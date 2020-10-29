#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
using namespace std;

#define N 10

const int SIZE = 4096;
const char *name_shm = "sh_mem";


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
		void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
		for(int i=0; i<N; i++){			
			*(((int*)ptr)+(i+1)) = i*2;
		}
		cout << "finaliza proceso hijo" << endl;
	}
	else{
		//wait(NULL);
		cout << "comienza proceso padre" << endl;
		void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
		for(int i=0; i<N; i++){			
			cout << *(((int*)ptr)+(i+1)) << endl;
		}
		shm_unlink(name_shm);
		cout << "finaliza proceso padre" << endl;
	}
	return 0;
}