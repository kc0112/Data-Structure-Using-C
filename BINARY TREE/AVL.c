 #include<stdio.h>
#include<stdlib.h>

 struct avl
 {
     int data;
     struct avl *left,*right;
 }*root,*temp,*newroot;

 typedef struct avl node;
 node* LLrot(node*);
node* RRrot(node*);
 node*insert (node*,int);
 int hieght(node*);
 void display(node*);
 int max(int,int);

 int main()
 {
  int n;
do{
          printf("ENTER THE NODE VALUE(-1 FOR NO NODE):");
          scanf("%d",&n);
          if(n!=-1)
          {
          root=insert(root,n);
          display (root);
          printf("\n");
          int BF=balancefact(root);
          printf("%d\n",BF);
          if(BF>1||BF<-1)
          {
              if(BF>1)
       {
           if(hieght(root->left->left)>hieght(root->left->right))
              root=LLrot(root);
           else
              {root->left=RRrot(root->left);
              root=LLrot(root);}

       }

          else if (BF<-1)
          {
             if(hieght(root->right->right)>hieght(root->right->left))
                root=RRrot(root);
             else
               {root->right=LLrot(root->right);
                root=RRrot(root);}
          }
           printf("UNBALANCED,CHANGIN TO BALANCED:\n");
           display(root);
            BF=balancefact(root);
           printf("\n%d\n",BF);
          }
          }
          else
          {
              printf("\n\nDISPLAYING FINAL TREE\n");
                display(root);
          }

}

   while(n!=-1);
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
         return (-1);
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

int balancefact(node*root)
{
    int b=hieght(root->left)-hieght(root->right);
    return (b);
}


node*LLrot(node*root)
{
    newroot=root->left;
    root->left=newroot->right;
    newroot->right=root;
    return (newroot);
}

node*RRrot(node*root)
{
    newroot=root->right;
    root->right=newroot->left;
    newroot->left=root;
    return (newroot);
}

