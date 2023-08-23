#include "csapp.h"

sigjmp_buf sigbuf; // 非本地跳转表

void sigchld_hand(int sig){

    // 默认没修改   
    // 需要阻塞信号

    siglongjmp(sigbuf, 1);
}

void * thread (void * argp){

    sleep(5);
    kill(getpid(), SIGCHLD);
}

char * tfgets(char * s, int n, FILE * stream)
{
    pid_t pid ;
    signal(SIGCHLD, sigchld_hand);
    pthread_t  tid;
    Pthread_create(&tid, NULL, thread, NULL);

    switch( sigsetjmp(sigbuf,1))
    {
        case 0:
            return fgets(s,  n,  stream);
        case 1:
            return NULL;
    }
    Pthread_join(tid, NULL);
    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */

    char buf[MAXLINE];
    if(tfgets(buf, MAXLINE, stdin) == NULL)
        printf("boom! \n");
    else   
        printf("%s! \n", buf);
    return 0;
}

