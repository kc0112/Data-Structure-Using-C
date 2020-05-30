#include<stdio.h>
#include<stdlib.h>

 struct avl
 {
     int data;
     struct avl *left,*right;
 }*root,*temp;

 typedef struct avl node;
 node*insert (node*,int);
 int hieght(node*);
 void display(node*);
 node* rotpos(node*);

 int main()
 {
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
         display (root);
         printf("\n");
           int l=hieght(root->left);
         int r=hieght(root->right);
         int BF=l-r;
     printf("%d-%d=%d\n",l,r,BF);

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
         if(n<root->data)
            root->left=insert(root->left,n);
         else
            root->right=insert(root->right,n);
         return root;
     }

 }

 int hieght(node*root)
 {
     if(root==NULL)
         return (0);
    int left,right;
    left = hieght(root->left);
    right=hieght (root->right);
    return (max(left,right)+1);
 }

 int max(int L,int R)
 {
     if(L>R)
    return L;
    else
        return R;
 }

 void display(node*root)
{
 if(root==NULL)
        return;
 display (root->left);
  printf("%d ",root->data);
 display (root->right);
}


