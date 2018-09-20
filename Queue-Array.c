#include <stdio.h>
#include <conio.h>

#define MAX 5   //Re-define your maximum

typedef struct queue
{
    int rear;
    int front;
    int size;
    int data[MAX];
}queue;

queue q;

void Init()
{
    q.rear = q.front = -1;
    q.size = 0;
}

int Full()
{
    if(q.size==MAX) return 1;
    return 0;
}

int Empty()
{
    if(q.size==0)
    {
        return 1;
    }
    return 0;
}

void EnQueue(int data)
{
    if(Full())
    {
        printf("The queue is full");

        return;
    }

    if(q.front < MAX -1)
    {
        q.data[++q.front] = data;
    }
    else
    {
        q.front = 0;
        q.data[q.front] = data;
    }
    q.size++;
}

int DeQueue()
{
    if(Empty())
    {
        printf("The queue is Empty\n");
    }
    q.size--;
    if(q.rear<MAX-1)
    {
        return q.data[++q.rear];
    }
    else
    {
        q.rear = 0;
        return q.data[q.rear];
    }
}

void menu()
{
    printf("1.Add\n");
    printf("2.Remove");
    printf("\n\t\t Select: ");
}

void main()
{
    Init();
    int choose;
    while(1)
    {
        menu();
        int temp;
        scanf("%d",&choose);
        char c;
        if(choose==1)
        {
            printf("Add n = ");
            scanf("%d",&temp);
            EnQueue(temp);
        }
        else if(choose==2)
        {
            if(Empty()) printf("Queue is empty!\n");
            else printf("Rear : %d\n",DeQueue());
        }
    }
}
