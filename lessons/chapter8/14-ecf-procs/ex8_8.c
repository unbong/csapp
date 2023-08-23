#include "csapp.h"

volatile long counter = 2;
void handler1(int sig){
    sigset_t mask , old_mask;
    Sio_puts("c 1 \n");
    Sigfillset(&mask);
    Sio_puts("c 2 \n");
    Sigprocmask(SIG_BLOCK, &mask, & old_mask);
    Sio_puts("c 3 \n");
    Sio_putl(--counter);
    Sio_puts("\n handler id ");
    Sio_putl(getpid());
     Sio_puts("\n  counter addr:  ");
    Sio_putl( &counter);
    Sio_puts("\n ");

    Sio_puts("parent handler id ");  
    Sio_putl( getppid());
    Sio_puts("\n ");
    
    Sigprocmask(SIG_SETMASK, &old_mask, NULL);
    Sio_puts("c 5 \n");
    _exit(0);
    
}

int main(int argc, char const *argv[])🀄️
{
    
    pid_t pid;
    printf("10 \n");
    sigset_t mask , old_mask;
    printf("%ld\n", counter);

    fflush(stdout);
    printf("11 \n");
    signal(SIGUSR1, handler1);
    printf("12 \n");
    if( (pid = Fork()) == 0 )
    {
        printf("11111child counter addr %p \n", &counter);
        pause();
        
    }
    printf("main pid: %d\n", getpid());
    Kill(pid, SIGUSR1);
    printf("2 \n");
    Waitpid(-1, NULL, 0);
    printf("3 \n");
    Sigfillset(&mask);
    printf("4 \n");
    Sigprocmask(SIG_BLOCK, &mask, &old_mask);
    printf("5 \n");
    printf("%ld, counter addr %p \n", ++counter, &counter);
    printf("6 \n");
    Sigprocmask(SIG_SETMASK, &old_mask, NULL);
    printf("7 \n");
    
    return 0;
}
