#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid, ppid;

    pid = fork();
    if (pid == 0)
    {
        pid = getpid();
        ppid = getppid();
        printf("Child process: PID = %d, PPID = %d\n", pid, ppid);
    }
    else
    {
        pid = getpid();
        printf("Parent process: PID = %d\n", pid);
    }

    return 0;
}
