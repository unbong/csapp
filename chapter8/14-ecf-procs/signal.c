#include "csapp.h"

void handler(int sig)
{
    int olderrno = errno;
    if(waitpid(-1, NULL, 0) < 0 ){
        Sio_error("waitpid error");
    }

    Sio_puts("Handler repead child\n");
    sleep(1);
    errno   = olderrno;
}

void handler2(int sig){
    int olderrno = errno;
    while( waitpid(-1, NULL, 0)>0 )
    {
        Sio_puts("Handler repead child\n");
    }
    Sleep(1);
    errno = olderrno;
}

int main(int argc, char const *argv[])
{
    
    int i , n;
    char buf[MAXBUF];

    int hendler = atoi(argv[argc-1]);

    if(handler == 1)
    {
        if(signal(SIGCHLD, handler) == SIG_ERR)
        {
            unix_error("signal error");
            
        }
    }
    else{
        if(signal(SIGCHLD, handler2) == SIG_ERR)
        {
            unix_error("signal error");
            
        }
    }
    

    for(i = 0; i<3; i++){
        if(Fork() ==0){
            printf("Hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    if( (n = read(STDIN_FILENO, buf, sizeof(buf))) < 0 )
    {
        unix_error("read");
    }

    printf("Parent processing input\n");
    while(1)
    {
        
    }
    return 0;
}
