#include "csapp.h"

sigjmp_buf sigbuf; // 非本地跳转表

void sigchld_hand(int sig){

    // 默认没修改   
    // 需要阻塞信号
    while(waitpid(-1, NULL , 0)>0)
        ;

    siglongjmp(sigbuf, 1);
}



char * tfgets(char * s, int n, FILE * stream)
{
    pid_t pid ;
    signal(SIGCHLD, sigchld_hand);
    if((pid = fork()) == 0){

        sleep(5);
        exit(0);
    }

    switch( sigsetjmp(sigbuf,1))
    {
        case 0:
            return fgets(s,  n,  stream);
        case 1:
            return NULL;
    }
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

