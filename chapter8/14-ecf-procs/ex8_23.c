#include "csapp.h"

volatile sig_atomic_t count = 0;

void sig_handler(int status)
{
    
    sigset_t mask, prev;
    pid_t pid;
    Sigfillset(&mask);
    Sio_puts("sig pid:");
    Sio_putl(getpid());
    //while((pid = waitpid(-1, NULL, 0)> 0))
    
        //Sigprocmask(SIG_BLOCK, &mask, &prev);
        
        count++;
        sleep(1);
        //Sigprocmask(SIG_SETMASK, &prev, NULL);
    
    
    return;
}
int main(int argc, char const *argv[])
{       
    signal(SIGUSR2, sig_handler);

    sigset_t mask, prev;
    
    Sigemptyset(&mask);
    Sigaddset(&mask, SIGUSR2);
    Sigprocmask(SIG_BLOCK, &mask, &prev);
    printf("pud:%d\n",getpid());
    if( Fork() ==0) 
    {
        for (size_t i = 0; i < 5; i++)
        {
            kill(getppid(), SIGUSR2);

            printf("set SIGUSR2 to parent  : pid %d\n", getpid());
        }
        exit(0);   
    }

    Wait(NULL);
    Sigprocmask(SIG_SETMASK, &prev, NULL);


    printf("counter=%d \n", count);
    exit(0);
}
