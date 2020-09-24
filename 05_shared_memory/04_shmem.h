#define BUFFER_SIZE 10

typedef unsigned char uchar;

const char *shmem_name = "SHMEM_DIGITAL3_04"; // Name of the shared memory section

typedef struct{
	int number;
    char char_n;
    // Más elementos
}item;

int shm_fd; // Descriptor of shared memory
void *ptr; // Pointer to shared memory
item *queue;
int *in, *out;