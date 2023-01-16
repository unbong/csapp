#include "csapp.h"
#include "sbuf.h"

void sbuf_init(sbuf_t * sbuf, int n)
{
    sbuf->buf = Calloc(n, sizeof(int));
    sbuf->front = 0;
    sbuf->rear = 0;
    sbuf->n = n;
    sem_init(&sbuf->mutex , 0 ,1);
    sem_init(&sbuf->items, 0, 0);
    sem_init(&sbuf->slots, 0, n);

}
void sbuf_deinit(sbuf_t * sbuf)
{
    Free(sbuf);
}

/*

*/
void sbuf_insert(sbuf_t * sbuf, int buf){

    P(&sbuf->slots);        // 检查槽位够不够？ 如果不够则挂起线程
    P(&sbuf->mutex);        // 对要更新的数据 加锁
    
    sbuf->buf[(++sbuf->rear) % sbuf->n] = buf;

    V(&sbuf->mutex);        // 解锁
    V(&sbuf->items);        // 增加要素的个数
}
int  sbuf_remove(sbuf_t * sbuf){

    P(&sbuf->items);
    P(&sbuf->mutex);

    int item = sbuf->buf[(++sbuf->front) % sbuf->n];
    
    V(&sbuf->mutex);
    V(&sbuf->slots);
    return item;

}