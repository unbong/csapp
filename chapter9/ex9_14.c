#include "csapp.h"

int main(int argc, char const *argv[])
{
    
    int fd = open("./hello.txt",O_RDWR, 0);

    char * buf = mmap(NULL, 20, PROT_WRITE, MAP_SHARED,fd,0);

    sprintf(buf,"Jello,work!\n");

    munmap(buf, 20);
    close(fd);
    return 0;
}

