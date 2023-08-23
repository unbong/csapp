#include "csapp.h"
#include "time.h"
#include "stdint.h"
#define N 500
#define M 1500
#define T_N  2

struct mat_info{
    
    int i;
    int j;
};

struct sigbuf{

    int front;
    int rear;
    int n ;
    struct  mat_info * mat_infos;
    sem_t slot;
    sem_t item;
    sem_t mutex;

};

long  a[N][M];
long b[M][M];
long res[N][M];
struct sigbuf sigbuf;


void sig_init(struct sigbuf * sig_buf, int n)
{
    sig_buf->mat_infos = (struct mat_info *)Calloc(n, sizeof(struct mat_info ));
    sig_buf->front = 0;
    sig_buf->rear = 0;
    sig_buf->n = n;
    sem_init(&sig_buf->item, 0, 0);
    sem_init(&sig_buf->slot,0, n);
    sem_init(&sig_buf->mutex,0, 1);
}

void sig_deinit(struct sigbuf * sig_buf)
{
    remove(sig_buf);
}

void sig_insert(struct sigbuf * sig_buf, struct mat_info *  mat_info)
{
    P(&sig_buf->slot);
    P(&sig_buf->mutex);
    sig_buf->mat_infos[(++sig_buf->front) % sig_buf->n] =  *mat_info;
    free(mat_info);
    V(&sig_buf->mutex);
    V(&sig_buf->item);
}

struct mat_info  sig_remove(struct sigbuf * sig_buf){

    P(&sig_buf->item);
    P(&sig_buf->mutex);
    struct mat_info  res = sig_buf->mat_infos[(++sig_buf->rear) % sig_buf->n];

    V(&sig_buf->mutex);
    V(&sig_buf->slot);
    return res;
}

void single_sum()
{

    for  (int i = 0; i< N; i++){
        for(int j = 0; j < M; j++){
            int sum = 0;
            for(int k = 0; k < M ; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
        }
    }

    return ;
}

void * thread(void * argp)
{
    
    int sum =0;
    Pthread_detach(Pthread_self());
    while(1)
    {
        struct  mat_info  mat = sig_remove(&sigbuf);
        
        for(int k = 0; k < M; k++)
        {   
            sum += a[mat.i][k] * b[k][mat.j];
        }
        res[mat.i][mat.j]= sum;
    }
    

    return NULL;
}

void multy_sum()
{


    for  (int i = 0; i< N; i++){
        for(int j = 0; j < M; j++){
            // int sum = 0;
            // for(int k = 0; k < M ; k++)
            // {
            //     sum += a[i][k] * b[k][j];
            // }
            struct mat_info *  mat  = Calloc(1, sizeof(struct mat_info));
            mat->i = i;
            mat->j = j;
            
            sig_insert(&sigbuf, mat);

        }
    }

    return ;
}

int main(int argc, char const *argv[])
{
    
    int n = 0;
    for(int i = 0; i<N;i++)
    {
        for(int j = 0; j < M; j++)
            a[i][j] =n++;
    }
    
    for(int i = 0; i<M;i++)
    {
        for(int j = 0; j < M; j++)
            b[i][j] =n++;
    }

    time_t result = time(NULL);
    printf("single start: %jd\n", (intmax_t)result);
    
    single_sum();
    time_t result1 = time(NULL);
    printf("single end: %jd\n", (intmax_t)result1);


    time_t result2 = time(NULL);
    printf("multy start: %jd\n", (intmax_t)result2);
    sig_init(&sigbuf, T_N);    
    pthread_t tids[T_N];
    for(int i = 0; i < T_N; i++)
    {
        Pthread_create(&tids[i], NULL, thread, NULL);
    }

    multy_sum();

    time_t result3 = time(NULL);
    printf("multy end: %jd\n", (intmax_t)result3);
    
    sig_deinit(&sigbuf);

    for (size_t i = 0; i < T_N; i++)
    {
        //Pthread_join(&tids[i], NULL);
    }
    

    return 0;
}



