#include<stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* left,*right;
}*root,*temp;
typedef struct tree node;
node* insert(node*,int);
void display(node*);
node* min (node*);
node* deletion(node*,int);

int main()
{
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,90);
    root=insert(root,20);
  display(root);
  printf("\n");
    deletion(root,40);
    printf("AFTER DELETION:\n");
    display(root);
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

node* deletion(node*root,int n)
{
       if (root==NULL)
         return root;
         else if(n<root->data)
       root->left=deletion(root->left,n);
        else if (n>root->data)
            root->right=deletion(root->right,n);

        else//found key to be deleted
        {
            //case 1 no child
            if(root->left==NULL&&root->right==NULL)
                {
                    free(root);
                    root=NULL;
                    return (root);
                }
                //case 2 one child
                else if(root->left==NULL)
                {
                    temp=root;
                    root=root->right;
                    free(temp);
                    return root;
                }
                else if(root->right==NULL)
                {
                    temp=root;
                    root=root->left;
                    free(temp);
                    return root;
                }
                //case 3 two children
                else
                {
                    temp=min(root->right);
                    root->data=temp->data;
                    root->right=deletion(root->right,temp->data);
                    return root;
                }
        }
    }
 node* min( node* root )
{
    if(root->left==NULL)               //while(root->left!=NULL) root=root->left; return root

        return root;
    else
    return min(root->left);
}

void display(node*root)
{
 if(root==NULL)
        return;
 display (root->left);
  printf("%d ",root->data);
 display (root->right);
}
