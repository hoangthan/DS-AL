#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *l;
    struct node *r;
    int data;
}* node;

node getNode(int data)
{
    node p = malloc(sizeof(struct node));
    p->l = p->r = NULL;
    p->data = data;
    return p;
}

node Add1(node root, int data)
{
    if(root==NULL) return getNode(data);
    else{
        if(data < root->data) root->l = Add1(root->l,data);
        else root->r = Add1(root->r,data);
    }
    return root;
    // root = Add1(root,data);
    // De quy.
}

node Add2(node* root, int data)
{
    if(*root==NULL) return *root;
    else{
        if(data < (*root)->data) (*root)->l = Add2(&(*root)->l,data);
        else (*root)->r = Add2(&(*root)->r, data);
    }
    return *root;
    //Add2(&root,data);
}

void Add3(node* root,int data)
{
    if(*root==NULL) *root = getNode(data);
    node temp = *root;
    node parent;
    while(temp!=NULL)
    {
        parent = temp;
        if(data < temp->data) temp = temp->l;
        else temp = temp->r;
    }
    if(data < parent->data) parent->l = getNode(data);
    else parent->r = getNode(data);
}

node Traverse(node root)
{
    if(root!=NULL)
    {
        Traverse(root->l);
        printf("  %d  ",root->data);
        Traverse(root->r);
    }
    //Traverse by recursion.
}

node Search1(node root, int data)
{
    if(root==NULL) return root;
    else
    {
        if(data < root->data) root = Search1(root->l,data);
        else if(data > root->data) root = Search1(root->r,data);
    }
    return root;
    //Searching by recursive.
}

node Search2(node root,int data)
{
    if(root==NULL) return root;
    else
    {
        while(root!=NULL && root->data!=data)
        {
            if(data < root->data) root = root->l;
            else if(data > root->data) root = root->r;
        }
    }
    return root;
    //Searching without recursion.
}

node findMin(node root)
{
    while(root->l!=NULL)
        root = root->l;
    return root;
}

node Delete(node root, int data)
{
    if(root==NULL) return root;
    else if(data < root->data) root->l = Delete(root->l,data);
    else if(data > root->data) root->r = Delete(root->r,data);
    else
    {
        if(root->l==NULL && root->r==NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->l==NULL)
        {
            node temp = root;
            root = root->r;
            free(temp);
        }
        else if(root->r==NULL)
        {
            node temp =  NULL;
            root = root->l;
            free(temp);
        }
        else
        {
            node temp = findMin(root->r);
            root->data = temp->data;
            root->r = Delete(root->r,temp->data);
        }
    }
    return root;
}

void menu()
{
    printf("\n1. Add");
    printf("\n2. Traverse.");
    printf("\n3. Search.");
    printf("\n4. Delete.");
    printf("\n5. Exit.");
    printf("\n\t >> Choose : ");
}

void execute()
{
    int choose;
    node root = NULL;
    node p;
    int n;
    while(1)
    {
        menu();
        scanf("%d",&choose);
        if(choose==1)
        {
            printf(" n = ");
            scanf("%d",&n);
            root = Add1(root,n);
            // Add2(&root,data);
            // Add3(&root,data);
        }
        else if(choose==2)
        {
            if(root==NULL) printf("Tree empty");
            else Traverse(root);
        }
        else if(choose==3)
        {
            printf(" Search n = ");
            scanf("%d",&n);
            p = Search1(root,n);
            p = Search2(root,n);
            if(p==NULL) printf("Khong tim thay");
            else printf("Found : %d",p->data);
        }
        else if(choose==4)
        {
            printf("Delete n = ");
            scanf("%d",&n);

            if(root==NULL)
                {
                    printf("Tree is empty!!!");
                    continue;
                }
            else root = Delete(root,n);
        }
        else if(choose==5)
        {
            printf("Terminated!!!");
            break;
        }
        else continue;
    }
}

void main()
{
   execute();
}
