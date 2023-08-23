#include "csapp.h"

int main(int argc, char const *argv[])
{
    struct addrinfo *p, *lisp, hints;
    char buf[MAXLINE];
    int rc, flags;

    // if(argc != 2)
    // {   
    //     printf("usage %s<domain> \n", argv[0]);
    //     exit(1);
    // }

    //char * src = argv[1];
    char * src = "wu.com";
    // clear hints
    memset(&hints, 0 ,sizeof(struct addrinfo));
    hints.ai_family = AF_INET;      // ipv4
    hints.ai_socktype = SOCK_STREAM; // connection only

    if(rc = getaddrinfo(src, NULL, &hints, &lisp) )
    {
        printf("getaddrinfo error: %s\n", gai_strerror(rc));
        exit(1);
    }

    // 堆集合进行遍历
    flags = NI_NUMERICHOST;  // 以数字形式显示 
    for(p = lisp; p ; p = p->ai_next){
        Getnameinfo(p->ai_addr,p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        printf("%s\n",buf);
    }

    Freeaddrinfo(lisp);

    return 0;
}
