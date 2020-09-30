//ORDINARY PIPES EXAMPLE
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(){
	int fd[2]; //file descriptor para crear pipe
	pid_t pid; //pid del proceso hijo

	//crear pipe
	if(pipe(fd) == -1){
		fprintf(stderr, "Fallo la creación del pipe\n");
		return 1;
	}

    // fd[READ_END] aka fd[0] : descriptor del extremo de lectura
    // fd[WRITE_END] aka fd[1] : descriptor del extremo de escritura

	//crear un proceso hijo
	pid = fork();

	if(pid < 0){
		//error en la creación de proceso hijo
		fprintf(stderr, "Error en la creación de proceso hijo\n" );
		return 1;
	}

	if(pid > 0){
        char write_msg[BUFFER_SIZE] = "PIPES PROCESOS";
		//espacio del proceso padre
		close(fd[READ_END]); //cerrar en end no usado del pipe (buena práctica para asegurar read() retorne 0)
		//escribir en pipe
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		//cerrar el end de escritura
		close(fd[WRITE_END]);
	}else{
        char read_msg[BUFFER_SIZE];
		//espacio del proceso hijo
		close(fd[WRITE_END]); //cerrar en end no usado del pipe (buena práctica)
		//leer pipe
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("lectura del pipe: %s\n", read_msg);
		//cerrar pipe
		close(fd[READ_END]);
	}
	return 0;
}