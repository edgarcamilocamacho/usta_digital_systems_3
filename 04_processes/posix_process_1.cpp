#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Parent process
int main()
{
    // Variable to store the child pid
    pid_t pid; // integer

    // Parent process creates child process.
    pid = fork();
    // From here, the code is execuded by two processes.
    printf("Parent process creates child process. %i \n", pid);

    if(pid < 0 ){
        // pid is less than 0 if child process could not be created
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if(pid == 0){
        // pid is 0 for the child
        printf("Executing child process... \n");
        // execlp() creates new process in memory, and delete the original process image
        execlp("./test_pipes_01", NULL);
        // the child does not come back to this code
        printf("Never...\n");
    }
    else{
        // The parent can execute other code, or just wait for the child finishing
        wait(NULL); // Parent process goes to 'fork a child' queue until one of its children finish
        // Parent process return to 'ready' queue
        printf("Child process finished, parent process continues \n");
        exit(0);
    }
}