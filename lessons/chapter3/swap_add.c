#include <stdio.h>
#include <string.h>

long swap_add(long * xp, long * yp)
{
    long x = *xp;
    long y = *yp;
    *xp = y;
    *yp = x;
    return x + y;
}

int main(int argc, char const *argv[])
{
    /* code */
    unsigned s  =  0x59b997fa;
    char as[20];
    sprintf(as, "%.8x" , s);
    puts(as);
    return 0;;
}
