#include "csapp.h"


int open_clientfd1( char * server ,  char * port){
    int clientfd;                           //  客户端文件描述符
    struct addrinfo hints, *listp, * p;     // 

    memset(&hints, 0, sizeof(hints));       // 

    hints.ai_socktype = SOCK_STREAM;        // 打开链接
    hints.ai_flags = AI_NUMERICSERV;        // 使用数字型端口号
    hints.ai_flags |= AI_ADDRCONFIG;        // 
    int  err_no;
    if( ( err_no= getaddrinfo(server, port, &hints, &listp)))
    {
        fprintf(stderr, "getaddrinfo failed. <%s>", gai_strerror(err_no));
        exit(1);
    }
    // 循环调用socket 如果可以连接则连接
    for(p = listp; p ; p = p->ai_next)
    {
        clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(clientfd < 0){
            continue;
        }

        if(connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
        {
            break;
        }

        close(clientfd);
    }

    freeaddrinfo(listp);

    if(!p) return -1;
    return clientfd;
}

int main(int argc, char *argv[])
{
    
    if(argc != 3){
        fprintf(stderr, "arg invalid\n");
        exit(1);
    }

    char  * server = argv[1];
    char  * port = argv[2];

    int clientfd = open_clientfd1(server, port);
    if(clientfd < 0)
    {
        fprintf(stderr, "clientfd is invalid. %d \n", clientfd);
        exit(1);
    }
    rio_t riop;
    rio_readinitb(&riop, clientfd);
    char buf[MAXLINE];
    while(Fgets(buf, MAXLINE, stdin) != NULL)
    {
        rio_writen(clientfd, buf, strlen(buf));
        rio_readlineb(&riop, buf, MAXLINE);
        fputs(buf, stdout);
    }

    close(clientfd);
    return 0;
}
