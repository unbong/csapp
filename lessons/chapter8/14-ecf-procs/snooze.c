#include "csapp.h"

int sec = 0;

void sigint_handler(int sig)
{
 
    return;
}



int main(int argc, char const *argv[])
{
    
    if(signal(SIGINT, sigint_handler) == SIG_ERR )
    {
        printf("signal error");
        exit(0);
    }

    sec = atoi(argv[argc-1]);

    int rc = sleep(sec);


    printf("slept for %d of %d secs\n",rc,sec );

    return 0;
}
