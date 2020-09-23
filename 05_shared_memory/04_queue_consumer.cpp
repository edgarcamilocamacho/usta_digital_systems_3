#include <stdio.h> //sprintf
#include <stdlib.h>
#include <string.h>	//strlen
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <time.h>

#define BUFFER_SIZE 10

typedef unsigned char uchar;

const int SIZE = 4096; // Size in bytes of the shared memory section
const char *name = "OS"; // Name of the shared memory section

typedef struct{
	int number;
}item;

int shm_fd; // Descriptor of shared memory
void *ptr; // Pointer to shared memory
item *queue;
int *in, *out;

int main(int argc, char** argv){
	srand (time(NULL));

	shm_fd = shm_open(name, O_RDWR, 0666);
	if(shm_fd==-1){
		printf("Memory shared could not be created.\n");
	}
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	queue = (item*)ptr;
	in = (int*)((uchar*)ptr + BUFFER_SIZE*sizeof(item));
	out = (int*)((uchar*)ptr + BUFFER_SIZE*sizeof(item) + sizeof(int));

	while(1){
		int x, char c;
		printf("Press Enter to receive 1 value.");
		getchar();
		if( *in == *out ){
			printf("Buffer empty, waiting for new values.\n");
			while(*in == *out);
		}
        x = queue[*out].number;
        c = queue[*out].char_n;
        printf("x=%d, x=%c\n", x, c);
		*out = (*out + 1) % BUFFER_SIZE;
	}

}