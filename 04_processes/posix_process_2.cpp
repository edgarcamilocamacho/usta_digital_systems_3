#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid_parent, pid_child, wpid;
	int a, b, status;
	pid_parent = getpid();
	printf("[P] Parent process with pid %d \n", pid_parent);

	printf("[P] This program creates a child process and performs the division of two numbers\n");
	printf("[P] Operation: a / b\n");
	printf("[P] Enter a: ");
	scanf("%d", &a);
	printf("[P] Enter b: ");
	scanf("%d", &b);

	pid_child = fork();

	if(pid_child == 0){
		// child
		printf("[C] Child process with pid %d \n", getpid());
		if(b!=0){
			printf("[C] %d / %d = %d \n", a, b, a/b);
			exit(EXIT_SUCCESS); // 0
		}else{
			printf("[C] Error: Division by zero can't be performed. \n");
			exit(EXIT_FAILURE); // 1
		}
	}
	else if(pid_child > 0){
		// parent
		wpid = wait(&status);
		if(wpid == pid_child){
			if(status==EXIT_SUCCESS){
				printf("[P] Child exited normally\n");
				// exit(EXIT_SUCCESS);
				return EXIT_SUCCESS;
			}
			else{
				printf("[P] Child process aborted\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	else{
		fprintf(stderr, "Fork failed \n");
		return 1;
	}
}