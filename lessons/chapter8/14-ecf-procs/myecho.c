#include "csapp.h"

int main(int argc, char const *argv[], char * envp[])
{
    
    printf("Comman-line arguments\n");
    int i = 0;
    while( argv[i] != NULL )
    {
        printf("\t arguments[%2d]: %s \n", i, argv[i++]);
        
    }

    
    printf("Comman-line arguments\n");
    i = 0;
    while(envp[i] != NULL)
    {
        printf("\t envp[%2d]: %s \n", i, envp[i++]);
        
    }

    return 0;
}
