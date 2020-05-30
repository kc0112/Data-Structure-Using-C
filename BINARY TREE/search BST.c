#include<stdio.h>
#include<stdlib.h>

typedef struct tree node;
node* insert(node*,int);
node* search (node*,int);
void display(node*);
struct tree
{
    int data;
    struct node* left,*right;
}*root;

int main()
{
    int key;
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,90);
    root=insert(root,80);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,70);
    root=insert(root,10);
    root=insert(root,60);
    display(root);
    printf("\nenter search key:");
    scanf("%d",&key);
    root=search(root,key);
    if(root==NULL)
        printf("key not found");
    else
    printf("key is found");
}

node* insert (node*root,int n)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=n;
        root->left=root->right=NULL;
         return root;
    }

    else
    {  if(n<root->data)
        root->left=insert(root->left,n);
       else
            root->right=insert(root->right,n);
                return root;
    }
}

node* search(node* root,int key)
{
    if(root==NULL)
        return root;
    else if(root->data==key)
        return root;
    else if(key<root->data)
    return (search(root->left,key));
    else
        return (search(root->right,key));

}

void display(node*root)
{
 if(root==NULL)
        return;
 display (root->left);
  printf("%d ",root->data);
 display (root->right);
}
