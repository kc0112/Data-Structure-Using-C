#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
}*root=NULL;

typedef struct node node;
node* newNode(int);
int main()
{
  root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);




    if(isBST(root))
        printf("yes");
    else
        printf("no");
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
 node* newNode(int data)
{
    node* root= ( node*)
                       malloc(sizeof( node));
  root->data = data;
  root->left = NULL;
 root->right = NULL;

  return(root);
}
