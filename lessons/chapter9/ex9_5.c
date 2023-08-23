#include "csapp.h"

int main(int argc, char const *argv[])
{
    
    if(argc !=3)
    {
        printf("arg invalid");
        exit(1);
    }

    char * filename = argv[1];
    int size = atoi(argv[2]);

    int fd = Open(filename, O_RDONLY, DEF_MODE);
    
    void * bufp =Mmap(bufp, size, PROT_READ, MAP_PRIVATE, fd, 0);

    write(STDOUT_FILENO, bufp, size);


    return 0;
}

