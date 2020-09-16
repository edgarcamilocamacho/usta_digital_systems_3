#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int n;                  // Number of processes.
int id;                 // Process ID
pid_t *pid_children;    // Array of process PIDs

// Function to find the process ID in the pid_children process.
int find_pid(pid_t pid){
    for(int i=0; i<n; i++){
        if(pid == pid_children[i])
            return i;
    }
    return -1;
}

// Function that stops the process execution
// for a while.
int delay_ms(int ms){
    clock_t before = clock();
    int msec = 0;
    do {
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
    } while ( msec < ms );
}

// Start of the parent process.
int main(int argc, char** argv)
{
    int i; // General use variable

    // Read the number of processes to launch
    if(argc == 2){
        n = atoi(argv[1]);
    }else if(argc == 1){
        n = 5;
    }else{
        printf("[P] Error: Wrong number of arguments.\n");
    }

    // Dynamical assigment of the pid_children array
    printf("[P] %d processes are going to be created.\n", n);
    pid_children = new pid_t[n];

    // Loop for process creation
    for(i=0; i<n; i++){
        // Creation of children
        pid_children[i] = fork();
        if(pid_children[i] == 0){
            // If it is the children, it breaks the for.
            id = i;
            printf("[C%d] Hijo creado\n", id);
            break;
        }
    }

    // Here there are 1 parent and 'n' processes.

    if(i==n){ // Parent
        // Loop to wait all the launched processes
        for(i=0; i<n; i++){
            int status, wid;
            pid_t wpid;
            // Get the pid and status of the finished process
            wpid = wait(&status);
            // Find the id of the finished process
            wid = find_pid(wpid);
            // Show the correspondent message
            if(status==0)
                printf("[P] Hijo %d finalizado satisfactoriamente.\n", wid);    
            else
                printf("[P] Hijo %d finalizado con error.\n", wid);    
        }
        // Finish the parent process
        printf("[P] Proceso padre finalizado\n");
        return 0;
    }else{ // Children
        // Set the seed
        srand (time(NULL)*id); 
        // Get a pseudo random number between 1000 and 5000.
        int ms = rand() % 4000 + 1000;
        // Wait for ms miliseconds
        delay_ms(ms);
        // Return sucess code if the id is even
        // and error if the id is odd.
        return id%2;
    }
}