#include <stdio.h>
#include <stdlib.h>

#define MS 4

typedef struct{
    int arr[MS];
    int front;
    int rear;
}FIFOQ;

void init(FIFOQ *ptq){
    ptq->front = -1;
    ptq->rear = -1;
}

int isEmpty(FIFOQ *ptq){
    if (ptq->front == -1)
        return 1;
    else
        return 0;
}

int isFull(FIFOQ *ptq){
    if ((ptq->rear == MS - 1 && ptq->front == 0) || (ptq->rear == ptq->front - 1))
        return 1;
    else
        return 0;
}

void enqueue(FIFOQ *ptq, int item){
    if (isFull(ptq))
    {
        printf("Queue is FULL!\n");
        return;
    }
    else
    {
        if (isEmpty(ptq))
        {
            ptq->front = ptq->rear = 0;
        }
        else if (ptq->rear == MS - 1)
        {
            ptq->rear = 0;
        }
        else
        {
            ++ptq->rear;
        }
        ptq->arr[ptq->rear] = item;
    }
}

void enqueueFront(FIFOQ *ptq, int item){
    if (isFull(ptq))
    {
        printf("Queue is FULL!\n");
        return;
    }
    else
    {
        if (ptq->rear == -1)
        {
            ptq->rear = ptq->front = MS - 1;
        }
        else if (ptq->front == 0)
        {
            ptq->front = MS - 1;
        }
        else
        {
            --ptq->front;
        }
        ptq->arr[ptq->front] = item;
    }
}

int dequeue(FIFOQ *ptq){
    if (isEmpty(ptq))
        return -9999;
    else
    {
        int temp = ptq->arr[ptq->front];

        if (ptq->front == ptq->rear)
        {
            ptq->front = ptq->rear = -1;
        }
        else if (ptq->front == MS - 1)
        {
            ptq->front = 0;
        }
        else
        {
            ++ptq->front;
        }

        return temp;
    }
}

int dequeueRear(FIFOQ *ptq){
    if (isEmpty(ptq))
        return -9999;
    else
    {
        int item = ptq->arr[ptq->rear];

        if (ptq->front == ptq->rear)
        {
            ptq->front = ptq->rear = -1;
        }
        else if (ptq->rear == 0)
        {
            ptq->rear = MS - 1;
        }
        else
        {
           -- ptq->rear;
        }

        return item;
    }
}

int peek(FIFOQ *ptq){
    if (isFull(ptq))
        return -9999;
    else
        return ptq->arr[ptq->front];
}

int main()
{
    FIFOQ q;
    init(&q);
    int choice,x;
    do
    {
        printf("\n1.Enqueue\n2.Enqueue Front\n3.Dequeue\n4.Dequeue Rear\n5.Peek\n6.Exit\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter element to insert: ");
                   scanf("%d",&x);
                   enqueue(&q,x);
                   break;
            case 2:printf("Enter element to insert from front: ");
                   scanf("%d",&x);
                   enqueueFront(&q,x);
                   break;
            case 3:x=dequeue(&q);
                   if(x==-9999)
                   printf("Queue is EMPTY\n");
                   else
                   printf("Deleted element = %d\n",x);
                   break;
            case 4:x=dequeueRear(&q);
                   if(x==-9999)
                   printf("Queue is EMPTY\n");
                   else
                   printf("Deleted element from rear = %d\n",x);
                   break;
            case 5:x=peek(&q);
                   if(x==-9999)
                   printf("Queue is EMPTY\n");
                   else
                   printf("Front element = %d\n",x);
                   break;
            case 6:printf("Exiting...\n");
                   break;
            default:printf("Invalid choice!\n");
        }
    }while(choice!=6);
    return 0;
}
