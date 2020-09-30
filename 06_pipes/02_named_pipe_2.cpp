//NAMED PIPES
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//Process 2: reads first on FIFO

#define SIZE 80

int main(){
	int fd;
	//path para FIFO
	char myfifo[] = "/home/camilo/myfifo";

	//crear archivo fifo (path, permisos)
	mkfifo(myfifo, 0666);

	char arr1[SIZE], arr2[SIZE];

	while(1){
		//abrir FIFO en solo lectura
		fd = open(myfifo, O_RDONLY);
		//leer FIFO
		read(fd, arr1, SIZE); // Bloqueante
        // (se va a quedar encerrado hasta que lleguen datos)
		//mostrar mensaje leido
		printf("Usuario 1: %s\n", arr1);
		close(fd);

		//abrir FIFO en modo escritura
		fd = open(myfifo, O_WRONLY);
		//leer array del usuario
		fgets(arr2, SIZE, stdin);
		//escribir en FIFO y cerrar archivo
		write(fd, arr2, strlen(arr2)+1);
		close(fd);
	}
	return 0;
}
