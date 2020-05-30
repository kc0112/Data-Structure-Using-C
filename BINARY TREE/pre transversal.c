#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
 struct node* left,*right;
}*root=NULL;

typedef struct node node;
node* insert( node*,int);
void inorder (node * );
void pre(node*);
void post(node*);
int c=1;
void main()
{
      root=insert(root,1);
      root=insert(root,2);
      root=insert(root,3);
      root=insert(root,4);
      root=insert(root,5);
      root=insert(root,6);
      printf("INORDER TRNSVERSAL : ");
      inorder(root);
      printf("\nPREORDER TRANSVERSAL : ");
      pre(root);
      printf("\nPOSTORDER TRANSVERSAL : ");
      post(root);
}

    node* insert(node*root,int n)
    {
        if(root==NULL)
        {
            root=(node*)malloc(sizeof(node));
            root->data=n;
            root->left=root->right=NULL;
            c++;
            return(root);
        }
        else
            {
                if(c%2==0)
                root->left=insert(root->left,n);
            else
                root->right=insert(root->right,n);
                return (root);
            }
    }

    void inorder(node * root)
{
    if(root==NULL)
         return;
        inorder(root->left);
    printf("%d ",root->data);
        inorder(root->right);
}

  void  pre(node * root)
{
      if(root==NULL)
         return;
    printf("%d ",root->data);
        pre(root->left);
        pre(root->right);
}

  void post(node * root)
{
    if(root==NULL)
         return;
   post(root->left);
      post(root->right);
          printf("%d ",root->data);
}


