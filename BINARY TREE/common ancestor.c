#include<stdio.h>
#include<stdlib.h>

typedef struct tree node;
node* insert(node*,int);
node *lca(node *, int , int );

struct tree
{
    int data;
    struct node* left,*right;
}*root,*ans;

int main()
{
    int v1,v2;
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,90);
    root=insert(root,80);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,70);
    root=insert(root,10);
    root=insert(root,60);
    root=insert(root,45);
    root=insert(root,43);
    printf("\nenter 2 keys:");
    scanf("%d %d",&v1,&v2);
    ans=lca(root, v1, v2 );
    printf("common ancestor is %d",ans->data);
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

node *lca(node *root, int v1, int v2 )
{

    if(root->data < v1 && root->data < v2)
    {
        return lca(root->right,v1,v2);
    }
    //Bigger than both
    if(root->data > v1 && root->data > v2){
        return lca(root->left,v1,v2);
    }

    //Else solution already found
    return root;
}


