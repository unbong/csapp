#include "./14-ecf-procs/csapp.h"

int main()
{
    
    pid_t pid = -1 ;
    int c = 1;

    pid = Fork();
    if(pid == 0)
    {
        printf("pid: %d, c: %d", pid, c++);
        exit(0);
    }

    printf("pid: %d, c: %d", pid, c++);

    return 0;
}
