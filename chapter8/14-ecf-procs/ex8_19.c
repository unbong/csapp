#include "csapp.h"

int main(int argc, char const *argv[])
{       
    for (size_t i = 0; i < 3; i++)
    {
        Fork();
    }

    printf("hello ! \n");
    exit(0);
}
