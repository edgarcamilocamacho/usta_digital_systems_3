#include <stdio.h> //sprintf
#include <stdlib.h>
#include <string.h>	//strlen
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <time.h>

const char *shmem_name = "SHMEM_DIGITAL3_03";

typedef struct{
	int number;
    bool flag;
}shmem_struct;

int shm_fd; // Descriptor of shared memory
shmem_struct *sh_mem;

int main(int argc, char** argv){
	shm_fd = shm_open(shmem_name, O_RDWR, 0666);
	if(shm_fd==-1){
		printf("Memory shared could not be accessed.\n");
	}
	sh_mem = (shmem_struct*)(mmap(0, sizeof(shmem_struct), PROT_WRITE, MAP_SHARED, shm_fd, 0));

	while(1){
		int x;
		printf("Press Enter to receive 1 value.\n");
		getchar();
        while(!sh_mem->flag);
        x = sh_mem->number;
        sh_mem->flag = false;
		printf("Received x = %d\n", x);
	}

}