#include <stdio.h>


long g_count = 0;
long l_count= 0;

long absdiff(long x, long y){
    long result ;
    if(x<y){
        l_count++;
        result = y-x;
    }else{
        g_count++;
        result = x-y;
    }

    return result;
}

int main(int argc, char const *argv[])
{

    return 0;
}
