#include<stdio.h>
#include<stdlib.h>
typedef struct tree node;
void display(node*);
node* insert(node*,int);
int hieght(node*);
int max(int,int);

struct tree
{
    int data;
    struct tree *left,*right;
}*root=NULL;


int main()
{

root=insert(root,40);
    root=insert(root,50);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,90);
    root=insert(root,20);
    root=insert(root,80);
    display(root);
    printf("\n%d is hieght",hieght(root));
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

int hieght (node*root)
{
    if(root==NULL)
        return (-1);
    int left=hieght(root->left);
    int right=hieght(root->right);
    return(max(left,right)+1);
}

int max(int L,int R)
{
    if(L>R)
        return L;
    else
        return R;
}
