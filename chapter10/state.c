#include "csapp.h"


int create_file(char * filename){
    umask(DEF_UMASK);
    int fd = open(filename, O_CREAT|O_TRUNC|O_WRONLY, DEF_MODE);

    char * buf = "just demo";
    write(fd, buf, strlen(buf));

    close(fd);
}

int main(int argc, char const *argv[])
{

    // struct stat buf;
    // stat("/root/cs_learn/chapter10/csapp.c",&buf);

    // printf("s");

    create_file("./create_demo2");
    return 0;
}
