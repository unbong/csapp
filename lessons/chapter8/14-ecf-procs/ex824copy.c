#include "csapp.h"


int main()
{
    char * c = "this is my first demo. ";
    char * n  = NULL;

    char * argv[100] ;
    int argc =0;
    int start= 0;
    int end = 0;


    while( (n = strchr(c,' '))  ){
        
        argv[argc++] = n;
        *n = NULL;
        printf("ss");
        c = n+1;
    }

    
    
    // for (size_t i = 0; i < argc; i++)
    // {
    //     /* code */

    //     printf("s: %s\n", argv[i]);
    // }
    
    
    return 0;
}
