#include <stdio.h>
#include <unistd.h>
int main() 
{
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID of Child: %d\n", getppid());
    }
    else {
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent PID of Parent (PPID): %d\n", getppid());
        printf("Child PID returned by fork(): %d\n", pid);
    }
    return 0;
}
