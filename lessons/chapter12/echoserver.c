#include "csapp.h"

int open_listenfd1(char * port){
    int listenfd, optval = 1;

    struct addrinfo hints, *listp, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICSERV;
    Getaddrinfo(NULL, port,&hints, &listp);

    for(p = listp; p ; p = p->ai_next)
    {
        if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0 )
            continue;

        // 清除
        Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        // 将监听描述符与地址进行绑定
        if( bind(listenfd, p->ai_addr, p->ai_addrlen ) == 0 ){
            break;
        }

        Close(listenfd);

    }

    Freeaddrinfo(listp);
    if(!p) return -1;
    // 监听
    if(listen(listenfd, LISTENQ)<0)
    {
        Close(listenfd);
        return -1;
    }

    return listenfd;
}

void echo(int connfd)
{
    size_t n;
    char buf[MAXLINE];
    char buf2[MAXLINE];
    rio_t rio;
    rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
    {
        printf("server received %d, bytes \n", (int)n);
        sprintf(buf2, "we received %s", buf);
        Rio_writen(connfd, buf2, n+12);
    }
}

int sigchld_hand(int sig){

    while(waitpid(-1, 0, WNOHANG) > 0)
    {
        ;
    }
    return 0;
}

int main(int argc, char  *argv[])
{
    
    if (argc != 2)
        unix_error("argument is error\n");

    
    signal(SIGCHLD, sigchld_hand);
    char * port = argv[1];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    char client_hostname[MAXLINE], client_port[MAXLINE];
    int listenfd = open_listenfd1(port);
    if(listenfd < 0)
    {
        printf("listenfd is invalid. %d\n", listenfd);
        exit(1);
    }
    int connfd;
    while(1){

        clientlen = sizeof(struct sockaddr_storage);
        connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
        if(fork() == 0)
        {
            Close(listenfd);
            Getnameinfo((SA *) & clientaddr, clientlen, client_hostname,MAXLINE, client_port, MAXLINE, 0);
            printf("Connected to (%s, %s)\n", client_hostname, client_port);
            echo(connfd);
            Close(connfd);
            exit(0);
        }
        
        Close(connfd);
    }


    return 0;
}
