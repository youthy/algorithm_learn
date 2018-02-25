#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Queue
{
    int front, rear, size;
    unsigned cap;
    int *array; 
} Queue;

// create
Queue* createQueue(unsigned cap)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->cap = cap;
    queue->front = queue->size = 0;
    queue->rear = queue->cap - 1;
    queue->array = (int*)malloc(sizeof(int) * queue->cap);
    return queue;
}

int isFull(Queue *queue)
{
    return queue->size == queue->cap;
}

int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

void enqueue(Queue *queue, int item)
{
    if(isFull(queue))
        return;
    queue->rear = queue->rear+1 % queue->cap;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    int ret = queue->array[queue->front++ % queue->cap];
    queue->size--;
    return ret;
}

int main(void)
{
    Queue *queue = createQueue(100);
    enqueue(queue, 1);
    enqueue(queue, 2);
    printf("dequeue:%d", dequeue(queue));
    printf("dequeue:%d", dequeue(queue));
    printf("dequeue:%d", dequeue(queue));
    return 0;
}