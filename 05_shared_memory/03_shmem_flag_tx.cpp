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
	srand (time(NULL));

	shm_fd = shm_open(shmem_name, O_CREAT | O_RDWR, 0666);
	if(shm_fd==-1){
		printf("Memory shared could not be created.\n");
        exit(1);
	}
	ftruncate(shm_fd, sizeof(shmem_struct));
	sh_mem = (shmem_struct*)(mmap(0, sizeof(shmem_struct), 
                                PROT_WRITE, MAP_SHARED, shm_fd, 0));

    sh_mem->number = 0;
    sh_mem->flag = false;

	while(1){
		int x;
		printf("Press Enter to send random number.\n");
		getchar();
		x = rand();
		printf("x = %d\n",x);
        if(sh_mem->flag){
            printf("Waiting for process P1 to read the previous data.\n");
            while(sh_mem->flag);
        }
        printf("Writing data.\n");
        sh_mem->number = x;
        sh_mem->flag = true;
	}
}	