#include<stdio.h>
#include<stdlib.h>
int queue[100],rear=-1,front=-1,c=1;
struct node
{
    int data;
    struct node*right,*left;
}*root;
typedef struct node node;
void enqueue(node*);
node* insert(node*,int);
node* dequeue(void);

int main()
{
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,90);
    root=insert(root,20);
    root=insert(root,60);

    enqueue(root);

    while(rear!=-1||front<=rear)
    {
      root=dequeue();
      printf("%d ",root->data);
      enqueue(root->left);
      enqueue(root->right);
    }
}

void enqueue (node*root)
{

    if(front==-1)
        front=0;
    if (root!=NULL)
     {
    rear++;
    queue[rear]=((node*)root);
     }
}

node* dequeue(void)
{
    int ele=queue[front];
    front++;
    return ((node*)ele);
}

node*insert(node*root,int n)
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
