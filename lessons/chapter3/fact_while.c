#include <stdio.h>


long fact_while(long n){
    
    long result = 1;
    while(n>0){
        result *=n;
        n--;
    }
    return result;
}

int main(int argc, char const *argv[])
{

    return 0;
}
