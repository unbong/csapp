#include "csapp.h"

char * tfgets(char * s, int n , FILE * stream)
{

    fd_set read_set, ready_set;
    FD_ZERO(&read_set);
    FD_SET(STDIN_FILENO, &read_set);

    struct timeval timeout;
    timeout.tv_sec = 5;
    ready_set = read_set;
    select(1, &ready_set, NULL, NULL, &timeout);

    if(FD_ISSET(STDIN_FILENO, &ready_set))
    {
        return fgets(s, n, stream);
    }
    else
        return NULL;
}


int main(int argc, char const *argv[])
{
    /* code */

    char buf[MAXLINE];
    if(tfgets(buf, MAXLINE, stdin) == NULL)
        printf("boom! \n");
    else   
        printf("%s", buf);
    return 0;
}
