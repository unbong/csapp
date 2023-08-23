#include "csapp.h"


int main()
{
    char * c = "this is my first demo. ";
    char  n  = NULL;

    char * argv[100] ;
    int argc =0;
    int start= 0;
    int end = 0;

    while( (n = *c) != NULL ){
        if( n == ' ')
        {
            strncpy(argv[argc++], c, (end- start));
            start = end;
            c = c+ end;
        }

        end ++;
    }

    
    for (size_t i = 0; i < argc; i++)
    {
        /* code */

        printf("s: %s\n", argv[i]);
    }
    
    
    return 0;
}
