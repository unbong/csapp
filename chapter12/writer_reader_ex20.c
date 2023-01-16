#include "csapp.h"
#define N 6

sem_t mutex_r;
sem_t mutex ;
sem_t mutex_w;
int cnt_w=0;
int cnt_r= 0;
int arr[N];

// 
void *   writter(void  * vargp){
    long i = (long) vargp;

    P(&mutex);
    cnt_w++;
    if(cnt_w>0)
    {
        P(&mutex_w);
    }
    V(&mutex);
    
    arr[i] = i;
    printf("writer output %d\n", arr[i]);

    P(&mutex);
    cnt_w--;
        
    V(&mutex_r);
    V(&mutex);
}

void * reader(void * vargp){
    long i = (long) vargp;
    V(&mutex);
    
    
    printf("reader output %d\n", arr[i]);
    
    P(&mutex_a);
    
}

/*
    读者优先模拟代码
*/
int main(int argc, char const *argv[])
{
    /* code */
    sem_init(&mutex, 0 , 1);
    sem_init(&mutex_r, 0, 1);
    sem_init(&mutex_w, 0, 1);
    pthread_t tids[N];

    for (size_t i = 0; i < N; i++)
    {
        
        if(i == 1||i==3){
            pthread_create(&tids[i], NULL, writter, i);
        }
        else
            pthread_create(&tids[i], NULL, reader, i);
    }

    for (size_t i = 0; i < N; i++)
    {
        /* code */
        pthread_join(tids[i], NULL);
    }
    

    return 0;
}
