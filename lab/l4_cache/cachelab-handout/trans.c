/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{

    // int i, j, tmp;

    // for (i = 0; i < N; i++) {
    //     for (j = 0; j < M; j++) {
    //         tmp = A[i][j];
    //         B[j][i] = tmp;
    //     }
    // }    
    // 分块
    int minSize ;
    int maxSize ;
    if(M > N) 
    {   minSize = N; maxSize = M;}
    else {   minSize = M; maxSize = N;}
    int block =  256 / maxSize;
    //int block = 16;
    int blockRowIndex = minSize /block;
    int blockColIndex = minSize /block;
    //int tmp = 0;
    int i ;
    int j ;
    int x ; 
    int y ;
    //int tmp ;
    // for(i = 0; i < N ; i++)
    // {
    //     for(j = 0; j < M; j++ ){
    //         B[i][j] = A[i][j];
    //     }
    // }
    //
    // for( i = 0; i< blockRowIndex; i++){
    //     for( j = 0; j < blockColIndex; j++)
    //     {
    //         for( x = 0; x < block; x++  )
    //         {
    //             for( y = 0; y < block ; y++)
    //             {
    //                 B[block * i + y][block* j+ x] = A[block * i + x][block* j+ y] ;
    //             }
    //         }
    //
    //         // for(int x = 0; x < block; x++  )
    //         // {
    //         //     for(int y = x; y < block ; y++)
    //         //     {
    //         //         tmp =  B[block * i + x][block* j+ y];
    //         //         B[block* j+ x][block * i + y] = 
    //         //     }
    //         // }
    //     }
    // }
    //
    // for ( i = 0; i < blockRowIndex; i++)
    // {
    //     for ( j = i ; j < blockColIndex; j++ )
    //     {
    //         for (x = 0; x< block; x++)
    //         {
    //             for( y = 0; y < block ; y++)
    //             {
    //                 tmp = B[block * i + x][block* j+ y] ;
    //                 B[block * i + x][block* j+ y] = B[block * j + x][block* i+ y] ;
    //                  B[block * j + x][block* i+ y] = tmp; 
    //             }
    //         }
    //     }
    // }

    for ( i = 0; i < blockRowIndex; i++)
    {
        for ( j = 0 ; j < blockColIndex; j++ )
        {
            for (x = 0; x< block; x++)
            {
                for( y = 0; y < block ; y++)
                {
            
                     B[block * j + y][block* i+ x] = A[block * i + x][block* j+ y] ;
                }
            }
        }
    }

    for(i = blockRowIndex * block; i < N  ; i++ )
    {
        for(j = 0; j < M ; j++ )
        {
            B[j][i] = A[i][j] ;
        }
    }

    for(j = blockColIndex * block; j < M ; j++ )
    {
        for(i = 0; i < M ; i++ )
        { 
            B[j][i] = A[i][j] ;
        }
    }



    // if (!is_transpose(M, N, A, B) ) {
    //     printf("failed transpose\n");
    // }
    
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

