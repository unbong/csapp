#include <stdio.h>

typedef unsigned char * byte_pointer;



void show_int(int x){
    showbyte((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
    showbyte((byte_pointer) &x, sizeof(float));
}


void show_pointer(void *  x){
    showbyte((byte_pointer) &x, sizeof(void *));
}


void showbyte(byte_pointer start , int size){
    for (size_t i = 0; i < size; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    

    // show_int(15);
    // show_float( 3.2);

    // int * s ;
    // int ss = 15;
    // s = &ss;
    //show_pointer(s);

    short x = 12345;
    short mx = -x;
    showbyte((byte_pointer) &x, sizeof(short));
    showbyte((byte_pointer) &mx, sizeof(short)); 
  
    return 0;
}