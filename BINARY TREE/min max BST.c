#include<stdio.h>
#include<stdlib.h>
typedef struct tree node;
void display(node*);
node* insert(node*,int);
node* min (node*);
node*max(node*);
struct tree
{
    int data;
    struct tree *left,*right;
}*root=NULL,*temp;


int main()
{
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,80);
    root=insert(root,20);
    root=insert(root,60);
    temp=root;
    display(root);
    root=min(temp);
    printf("\n%d is the min value",root->data);
    root=max(temp);

    printf("\n%d is the max value",root->data);
}

node* insert (node* root,int n)
{
    if (root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=n;
        root->left=root->right=NULL;
        return root;
    }

    else
   {
        if (n<root->data)
            root->left=insert(root->left,n);
        else
            root->right=insert (root->right,n);
        return (root);
    }
}

void display(node*root)
{
 if(root==NULL)
        return;
 display (root->left);
  printf("%d ",root->data);
 display (root->right);
}

node* min (node*root)
{
    if(root->left==NULL)
        return root;
    else if(root>root->left)
        return (min(root->left));
}

node* max (node*root)
{
    if(root->right==NULL)
        return root;
    else if(root<root->right)
        return (max(root->right));
}
