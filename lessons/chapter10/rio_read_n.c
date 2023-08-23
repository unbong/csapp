#include "csapp.h"



int main(int argc, char const *argv[])
{
    
    int fd = Open("./csapp.h",O_RDONLY,DEF_MODE);
    rio_t  rio;
    rio_readinitb(&rio, fd);

    char buf[2048];
    rio_readlineb(&rio, buf,2048);
    
    char * c = buf;
    while(*c != '\n')
    {
        rio_writen(STDOUT_FILENO, c, 1);
        c++;
    }

    exit(0);
}
