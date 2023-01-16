#include "csapp.h"
#define N 4

sem_t mutex;
sem_t priority_flg ;
int cnt=0;
int arr[N];

// 
void *   writter(void  * vargp){
    long i = (long) vargp;
    P(&mutex);
    arr[i] = i;
    printf("writer output %d\n", arr[i]);
    V(&mutex);
}

void * reader(void * vargp){
    long i = (long) vargp;

    P(&priority_flg);
    cnt++;
    if(cnt == 1)
        P(&mutex);
    V(&priority_flg);

    printf("reader output %d\n", arr[i]);
    sleep(4);
    P(&priority_flg);
    if(cnt == 1)
        V(&mutex);
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
    pthread_t tids[N];

    for (size_t i = 0; i < N; i++)
    {
        
        if(i == 1){
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
