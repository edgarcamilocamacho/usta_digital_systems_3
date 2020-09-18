//IPC between producer and consumer processes bt shared memory

#include <stdio.h> //sprintf
#include <stdlib.h>
#include <string.h>	//strlen
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap


const int SIZE = 4096; // Size in bytes of the shared memory section
const char *name = "SHMEM_NAME"; // Name of the shared memory section
const char *messsage_0 = "Hello "; // Beginning ot the string to be shared
const char *messsage_1; // End or the string to be shared

int main(int argc, char** argv){
    
    if(argc==2){
        messsage_1 = argv[1];
    }else if(argc==1){
        messsage_1 = "World!\n";
    }else{
        printf("[P] Error. Incorrect number of parameters.\n");
        return 1;
    }

	int shm_fd; // Descriptor of shared memory
	void *ptr; // Pointer to shared memory

	// shm_open creates the shared memory and return the descriptor
	// name: must be known by all the processes that are goint to access the shared memory
	// acess memory: O_CREAT (creates the shared memory if it does not exists) 
	// 				 OR
	// 				 O_RDWR (R/W access)
	// 0666 permisions
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	// ftruncate configures the shared memory size
	ftruncate(shm_fd, SIZE);
	// mmap returns the ponter to the shared memory
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	// Write the first message on the shared memory
	sprintf((char *)ptr, "%s", messsage_0);
	// Move the pointer to the end of the first message + 1
	ptr = (void *) ( (char *)ptr + strlen(messsage_0) );
	// Srite the second message
	sprintf((char *)ptr, "%s", messsage_1);
	// Move the pointer to the end of the second message + 1
	ptr = (void *) ( (char *)ptr + strlen(messsage_1) );

	return 0;
}