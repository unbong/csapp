#include "csapp.h"
typedef struct{
    int maxfd;
    fd_set read_set;
    fd_set ready_set;
    int nready;
    int maxi;
    int clientfd[FD_SETSIZE];
    rio_t clientrio[FD_SETSIZE];

} pool;

init_pool(int listenfd, pool * pool){

    int i;
    pool->maxi  = -1;
    for(i = 0; i< FD_SETSIZE;i++)
        pool->clientfd[i] = -1;
    
    pool->maxfd = listenfd;
    FD_ZERO(&pool->read_set);
    FD_SET(listenfd, &pool->read_set);
}



int main(int argc, char const *argv[])
{
    /* code */

    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    static pool pool;

    if(argc != 2)
        unix_error("argc invalid");
    
    listenfd = Open_listenfd(argv[1]);


    while(1){

    }

    return 0;
}
