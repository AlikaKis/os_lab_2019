#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t chld_pid;
    chld_pid = fork();
    if (chld_pid > 0) 
    {
        printf("Parent process\n");
        sleep(15); 
        printf("Parent process, program finished\n");
    }
    else
    {
        printf("Child process,  program finished\n");
        exit(0);
    }
    return 0;
}