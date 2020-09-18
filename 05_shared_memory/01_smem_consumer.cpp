//comnunicación entre procesos producer y consumer a traves de memoria compartida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

const int SIZE = 4096; // Size in bytes of the shared memory
const char *name = "SHMEM_NAME"; // Name of the shared memory

int main(int argc, char** argv){

	int shm_fd; // Descriptor of the shared memory
	void *ptr; // Pointer to the shared memory

	// Open the shared memory with only read permissions
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if(shm_fd==-1){ 
		printf("The shared memory does not exists.\n");
		exit(1);
	}
	// Get the pointer
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	// Show the content
	printf("%s", (char *)ptr);

	// If there are arguments, remove the shared memory
	if(argc>1){
		shm_unlink(name);
	}
	return 0;

}