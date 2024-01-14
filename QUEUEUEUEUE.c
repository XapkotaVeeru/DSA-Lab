#include <stdio.h>
#define MAXSIZE 10
int front = -1, rear = -1;
int queue[MAXSIZE];
int isQueueFull()
{
    if(rear == MAXSIZE-1) return 1;
    else return 0;
}
int isQueueEmpty()
{
    if(front == -1) return 1;
    else return 0;
}

void enQueue(int data)
{
    if(isQueueFull())
    {
        printf("the queue is full");
    }
    else{
        rear = rear + 1;
        queue[rear] = data;
    }
}
void deQueue()
{
    if(isQueueEmpty()){
        printf("queue is empty");
    }
    else{
        printf("%d is dequeued",queue[front]);
        front = front + 1;
    }
}
void display()
{
    for(int i = front; i<= rear; i++)
    {
        printf("%d\n",queue[i]);
    }
}

int main(){
    deQueue();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();
    return 0;
}
