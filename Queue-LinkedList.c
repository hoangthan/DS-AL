#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
}* queue;

queue getNode()
{
    queue p = malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("Memory is not enough!!!");
        return NULL;
    }
    return malloc(sizeof(struct node));
}

queue head, tail;

void Init()
{
    head = tail = NULL;
}

int Empty()
{
    if(head==NULL) return 1;
    return 0;
}

void Add(int data)
{
    if(head==NULL)
    {
        head = getNode();
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    else
    {
        queue q = getNode();
        tail->next = q;
        tail=q;
        tail->next = NULL;
        tail->data = data;
    }
}

int Remove()
{
    if(!Empty())
    {
        int n = head->data;
        queue p = head;
        head = head->next;
        free(p);
        return n;
    }
}

void menu()
{
    printf("1. Add\n");
    printf("2. Remove.\n");
    printf("   >> Choose : ");
}

void main()
{
    int choose;
    int n;
    Init();
    while(1)
    {
        menu();
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("n = ");
            scanf("%d",&n);
            Add(n);
        }
        else if(choose==2)
        {
            if(Empty()) printf("The queue is empty\n");
            else printf("Rear : %d\n",Remove());
        }
        else continue;
    }
}

