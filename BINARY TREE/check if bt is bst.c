#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
}*root=NULL;

typedef struct tree node;
node* insert(node*,int);

int c=1;

int main()
{

    root=insert(root,10);
    root=insert(root,4);
    root=insert(root,19);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,17);


    if(isBST(root))
        printf("yes");
    else
        printf("no");
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

int isBST(node* root) {

    int min=-999, max=999;

   return(BSTUtil(root,min,max));
}
int BSTUtil( node* root, int min, int max) {

   if (root==NULL)
      return 1;

   if (root->data <min || root->data > max)
      return 0;

      return (BSTUtil(root->left, min, root->data-1)&& BSTUtil(root->right, root->data+1, max));
}
