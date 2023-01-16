#include "csapp.h"
volatile sig_atomic_t counter = 1;

void signal_handler(int status)
{
    counter=-1;
}

int main(int argc, char const *argv[])
{   
    signal(SIGCHLD, signal_handler);
    
    if(Fork()==0)
    {
        counter--;
        printf("child counter=%d\n", counter);
        exit(0);
    }

    else{
        //printf("parent 1  counter=%d\n", counter);
        
        sleep(10);
        Wait(NULL);
        printf("parent counter=%d\n", ++counter);
    }
    exit( 0);
}
