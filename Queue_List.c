#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 5
#define NULLKEY -32768

typedef int elementType;    //数据类型

typedef struct {
    elementType* array;
    int head;
    int tail;
    int curSize;
} Queue;

Queue* QueueCreate() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(queue) {
        queue->array = (elementType*)malloc(MAXSIZE * sizeof(elementType*));
        queue->head = -1;
        queue->tail    = -1;
        queue->curSize = 0;
    }
    for (int i=0; i < MAXSIZE; i++) {
        queue->array[i] = NULLKEY;
    }
    return queue;
}

bool QueueIsEmpty(Queue* q) {
    return q->head == -1;
}

bool QueueIsFull(Queue* q) {
//    return q->curSize == MAXSIZE;
    return (q->tail + 1) % MAXSIZE == q->head;
}

void QueuePush(Queue* q, elementType x) {
    if(QueueIsFull(q)) {
        return;
    }
    if (QueueIsEmpty(q)) {
        q->head = 0;
    }

    q->tail = (q->tail + 1) % MAXSIZE;
    q->array[q->tail] = x;
    q->curSize++;
}

void QueuePop(Queue* q) {
    if (QueueIsEmpty(q)) {
        return;
    }
    q->array[q->head] = NULLKEY;
    if (q->tail == q->head) {
        q->curSize = -1;
        q->tail    = -1;
        q->curSize = 0;
        return;
    }

    q->head = (q->head + 1) % MAXSIZE;
    q->curSize--;
}

elementType QueueFront(Queue* q) {
    if (QueueIsEmpty(q)) {
        return -1;
    }
    return q->array[q->head];
}

elementType QueueRear(Queue* q) {
    if (QueueIsEmpty(q)) {
        return -1;
    }
    return q->array[q->tail];
}

void QueueFree(Queue* q) {
    if (q) {
        free(q->array);
        free(q);
    }
}

int main()
{
    Queue* queue = QueueCreate();
    QueuePush(queue, 5);
    QueuePush(queue, 6);
    QueuePush(queue, 7);
    QueuePush(queue, 8);
    QueuePush(queue, 9);
    QueuePush(queue, 10);
    QueuePop(queue);
    QueuePush(queue, 10);
    elementType front = QueueFront(queue);
    elementType rear = QueueRear(queue);
    QueueFree(queue);
    return 0;
}
