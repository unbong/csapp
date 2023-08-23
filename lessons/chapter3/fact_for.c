#include <stdio.h>


long fact_for(long n){
    
    long i ;
    long result = 1;
    for(i = 2; i<=n; i++){
        result *=i;
       
    }
    return result;
}

int main(int argc, char const *argv[])
{

    return 0;
}
 