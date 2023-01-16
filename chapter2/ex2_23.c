#include <stdio.h>

typedef unsigned char * byte_pointer;

void showbyte(byte_pointer start , int size){
    for (size_t i = 0; i < size; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
    
}

int func1(unsigned x){
    
    return (int)((x << 24) >> 24);
}

int func2(unsigned x){
    
    return ((int) x << 24 >> 24);
}


int main(int argc, char const *argv[])
{
    
    unsigned x = 0x00000076;
    int m = func1(x);
    showbyte((byte_pointer) &m, sizeof(int));
    m = func2(x);

    showbyte((byte_pointer) &m, sizeof(int));

    x = 0x87654321;
    m = func1(x);
    showbyte((byte_pointer) &m, sizeof(int));
    m = func2(x);

    showbyte((byte_pointer) &m, sizeof(int));

    x = 0x000000C9;
    m = func1(x);
    showbyte((byte_pointer) &m, sizeof(int));
    m = func2(x);

    showbyte((byte_pointer) &m, sizeof(int));

    x = 0xEDCBA987;
    m = func1(x);
    showbyte((byte_pointer) &m, sizeof(int));
    m = func2(x);

    showbyte((byte_pointer) &m, sizeof(int));

    return 0;
}

