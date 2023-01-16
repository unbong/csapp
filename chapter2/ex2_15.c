#include <stdio.h>

int isEqual(int x, int y){
    int m =  x ^ y;
    return !m;
}


int main(int argc, char const *argv[])
{
    
    int x = 32;
    int y = 11;

    int s = isEqual(x, y);

    printf("%d \n", s);

    s = isEqual(32, 32);
    printf("%d \n", s);


    //printf("x = %" PRId32);
    return 0;
}

