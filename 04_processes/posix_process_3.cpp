#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//proceso padre: createProcessUnix
int main()
{
	pid_t pid_parent, pid_child;
	pid_parent = getpid();

	printf("Parent process with pid %d \n", pid_parent);
	pid_child = fork();

	if(pid_child == 0){
		//child
		printf("Child process with pid %d \n", getpid());
		clock_t before = clock();
		int msec = 0, trigger = 20000;
		do {
		   // Do something to busy the CPU just here while you drink a coffee
		   // Be sure this code will not take more than `trigger` ms

		  clock_t difference = clock() - before;
		  msec = difference * 1000 / CLOCKS_PER_SEC;
		} while ( msec < trigger );
		printf("Child finished \n");
		exit(0);
	}
	else if(pid_child > 0){
		// PROCESAMIENTO DEL PADRE //
		printf("Padre esperando una tecla\n");
		getchar();
		// FIN DEL PROCESAMIENTO DEL PADRE //

		printf("Padre esperando a que el hijo termine\n");
		wait(NULL);

		exit(0);
	}
	else{
		fprintf(stderr, "Fork failed \n");
		return 1;
	}
}
