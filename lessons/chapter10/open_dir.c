#include "csapp.h"



int main(int argc, char const *argv[])
{
    
    DIR * dirs;
    struct  dirent * dep;

    dirs = opendir(argv[1]);
    errno = 0;
    while( (dep = readdir(dirs)) != NULL )
    {
        printf("found file %s\n", dep->d_name);

    } 

    if(errno != 0)
        unix_error("read");
    
    closedir(dirs);
    exit(0);
}
