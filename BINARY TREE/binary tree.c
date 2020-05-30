#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* left,*right;
};

typedef struct tree node;
node* insert(node*,int);
void display(node*);
 int c=1;

int main()
{
    struct node*root=NULL;

    int n,choice;
do{
    printf("ENTER CHOICE,1,2,3:");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
       {
        printf("ENTER THE NODE VALUE:");
        scanf("%d",&n);
        root=insert(root,n);
        break;
     }
    case 2:
     {
         display (root);
         break;
     }
    case 3:
        {
            return 0;
            break;
        }
    }
}while(choice!=3);
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

void display(node * root)
{
    if(root==NULL)
        return;
        display(root->left);
    printf("%d\n",root->data);
        display(root->right);
}


