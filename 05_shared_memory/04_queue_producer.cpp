#include <stdio.h> //sprintf
#include <stdlib.h>
#include <string.h>	//strlen
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <time.h>

#include "04_shmem.h"

int main(int argc, char** argv){
	srand (time(NULL));

	shm_fd = shm_open(shmem_name, O_CREAT | O_RDWR, 0666);
	if(shm_fd==-1){
		printf("Memory shared could not be created.\n");
		exit(1);
	}
	ftruncate(shm_fd, BUFFER_SIZE*sizeof(item) + 2*sizeof(int) );
	ptr = mmap(0, BUFFER_SIZE*sizeof(item) + 2*sizeof(int) , PROT_WRITE, MAP_SHARED, shm_fd, 0);
	queue = (item*)ptr;
	in = (int*)((uchar*)ptr + BUFFER_SIZE*sizeof(item));
	out = (int*)((uchar*)ptr + BUFFER_SIZE*sizeof(item) + sizeof(int));

	*in = 0;
	*out = 0;

	while(1){
		int x; char c;
		printf("Press Enter to send random number.");
		getchar();
		x = rand();
        c = 'A' + (char)(x%26);
		printf("x=%d, x=%c\n", x, c);
		if( (*in+1)%BUFFER_SIZE == *out ){
			printf("The buffer is full, waiting for a space in the queue...\n");
			while( (*in+1)%BUFFER_SIZE == *out );
		}
		queue[*in].number = x;
        queue[*in].char_n = c;
		printf("Value sent!\n");
		*in = (*in+1)%BUFFER_SIZE;
	}

}	
