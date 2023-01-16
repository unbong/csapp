#include <semaphore.h>

typedef struct {
    int * buf;      // 缓冲区数组
    int n;          // 最大槽数
    int front;      // 第一个元素
    int rear;       // 最后一个元素
    sem_t mutex;    // 保护缓冲区的锁（二元锁）
    sem_t slots;    // 记录槽位的锁
    sem_t items;    // 记录元素个数的锁
} sbuf_t;

void sbuf_init(sbuf_t * sbuf, int n);
void sbuf_deinit(sbuf_t * sbuf);
void sbuf_insert(sbuf_t * sbuf, int buf);
int sbuf_remove(sbuf_t * sbuf);
