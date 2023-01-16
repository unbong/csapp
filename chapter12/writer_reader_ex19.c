#include "csapp.h"
#define N 6

sem_t mutex;
sem_t priority_flg ;
sem_t mutex_a;
int cnt=0;
int arr[N];

// 
void *   writter(void  * vargp){
    long i = (long) vargp;
    P(&mutex_a);
    P(&mutex);
    arr[i] = i;
    printf("writer output %d\n", arr[i]);
    V(&mutex);
    V(&mutex_a);
}

void * reader(void * vargp){
    long i = (long) vargp;

    P(&priority_flg);
    cnt++;
    if(cnt == 1)
    {
        P(&mutex);

    }
        
    V(&priority_flg);

    printf("reader output %d\n", arr[i]);
    
    P(&priority_flg);
    if(cnt == 1)
    {

        V(&mutex);
    }
        
    
    cnt--;
    V(&priority_flg);

}

/*
    读者优先模拟代码
*/
int main(int argc, char const *argv[])
{
    /* code */
    sem_init(&mutex, 0 , 1);
    sem_init(&priority_flg, 0, 1);
    sem_init(&mutex_a, 0, 1);
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
