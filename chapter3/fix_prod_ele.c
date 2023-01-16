#include <stdio.h>
#define N 16
typedef int fix_matrix[N][N];

int fix_prod_ele(fix_matrix a,fix_matrix b,  long i, long k)
{
    long j ;
    int result = 0;
    for(j = 0; j < N; j++){
        result = a[i][j] * b[j][k];
    }

    return result;
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
