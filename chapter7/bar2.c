#include <stdio.h>
void f();
int y = 15213;
int x = 15212;


int main(int argc, char const *argv[])
{
    printf("x=0x%x , y=0x%x\n", x, y);
    f();
    printf("x=0x%x , y=0x%x\n", x, y);
    return 0;
}
