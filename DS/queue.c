#include <stdio.h>
#include <stdlib.h>

typedef int element;

struct cell
{
    element data;
    struct cell *next;
};

typedef struct
{
    struct cell *front, *rear;
} queue;

queue createQueue()
{
    queue q;
    q.front = q.rear = NULL;
    return q;
}

int isEmptyqQueue(queue q)
{
    return q.front == NULL;
}

int EnQueue(queue *q, element e)
{
    struct cell *temp;
    temp = (struct cell *)malloc(sizeof(struct cell));
    if (!temp)
        return 0;
    temp->data = e;
    temp->next = NULL;
    if (q->rear == NULL) // EMPTY QUEUE
        q->front = q->rear = temp;
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
    return 1;
}

int DeQueue(queue *q)
{
    struct cell *temp;
    if (isEmptyqQueue(*q))
        return 0;
    temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) // Empty queue
        q->rear = NULL;
    return 1;
}

int Front(queue q, element *e)
{
    if (isEmptyqQueue(q))
        return 0;
    *e = q.front->data;
    return 1;
}

// =============================================================================
// EXERCISE 1
// Sort distinct elements of a queue
// Even elements are in the same order in the beginning
// =============================================================================

int main()
{
    return 0;
}