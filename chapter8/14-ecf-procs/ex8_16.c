#include "csapp.h"
int counter = 1;
int main(int argc, char const *argv[])
{   
    
    if(Fork()==0)
    {
        counter--;
        printf("child counter=%d\n", counter);
        exit(0);
    }

    else{
        printf("parent 1  counter=%d\n", counter);
        Wait(NULL);
        printf("parent counter=%d\n", ++counter);
    }
    exit( 0);
}
