#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *queuearr;
    int front, rear, size, capacity;
} Queue;

Queue *initialize(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->queuearr = (int *)malloc(capacity * sizeof(int));
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    return queue;
}

bool isEmpty(Queue *queue)
{
    if (queue->size == 0)
        return true;
    return false;
}

bool isFull(Queue *queue)
{
    if (queue->size == queue->capacity)
        return true;
    return false;
}

void push(Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->queuearr[q->rear] = data;
    q->size += 1;
}

int pop(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return INT_MIN;
    }
    int temp = q->queuearr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size -= 1;
    return temp;
}

int main()
{
    Queue *q = initialize(5);
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    while (q->size)
        printf("%d ", pop(q));

    push(q, 1);

    printf("\n%d %d", isEmpty(q), isFull(q));
    return 0;
}
