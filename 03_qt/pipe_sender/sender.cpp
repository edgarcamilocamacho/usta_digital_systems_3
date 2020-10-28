//NAMED PIPES
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 80

int main(){
	int fd;
	char myfifo[] = "/tmp/myfifo";

	mkfifo(myfifo, 0666);

	char text[SIZE];

    printf("Abriendo tuberia (esperando a que el otro extremo se abra)...\n");
    fd = open(myfifo, O_WRONLY);
    printf("Tuberia abierta\n");

	while(1){
		printf("Ingrese el texto a enviar: ");
		fgets(text, SIZE, stdin);
        printf("Enviando texto '%s'\n", text);
		write(fd, text, strlen(text)+1);
        printf("Texto enviado\n");
	}
    close(fd);
	return 0;
}
