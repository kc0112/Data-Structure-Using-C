#include<stdio.h>
#include <stdlib.h>
void enqueue(void);
void dequeue(void);
node* insert(node*,int);

struct tree
{
    char data;
    struct tree* left,*right;
}*root;

struct queue
{
    int name;
    struct node *next;
}*new,*temp,*rear,*front;

typedef struct tree node;

int main()
{
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,60);
    root=insert(root,70);
    root=insert(root,80);

}
node* insert(node*root,int n)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof (node));
        root->left=root->right=NULL;
        root->data=n;
        c++;
        return root;
    }
    else
    {
        if(c%2==0)
        root->left=insert(root->left,n);
        else
        root->right=insert(root->right,n);
        return root;
    }
}

void enqueue()
{
    int ele;
    new=(struct queue*)malloc(sizeof(struct queue));
    printf("ENTER ELEMENT TO BE ENQUEUED:");
    scanf("%d",&ele);
    new->data=ele;
    new->next=NULL;
    if(rear==NULL)
    {
        front=new;
        rear=new;
    }
    else
        rear->next=new;
    rear=new;
}

void dequeue()
{
    if(front==NULL)
    printf("QUEUE IS EMPTY");
    else
    {
        temp=front;
        printf("%d IS DELETED",temp->data);
        front=front->next;
        free(temp);
    }

}

