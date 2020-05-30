#include<stdio.h>
#include<stdlib.h>
struct L1
{
 int data;
 struct L1* next;
}*head,*tail,*newnode,*temp;
struct L2
{
    int data;
    struct L2 *next;
}*HEAD,*TAIL,*NEWNODE,*TEMP;
typedef struct L2 L2;
typedef struct L1 L1;
int main()
{
    int n,i,m,flag=0;
    printf("enter no. of nodes in LL1:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        insert();
    }
    printf("enter no. of nodes in LL2:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        INSERT();
    }


        TEMP=HEAD;
        temp=head;
      while(temp!=NULL||TEMP!=NULL)
        {
         if(temp->data==TEMP->data)
        {
        temp=temp->next;
        TEMP=TEMP->next;
        }
        else
        {
             flag=1;
             break;
        }
       }
       if(flag==1)
        printf("not equal");
        else
        printf("equal");
}

void insert()
{
    int value;
    newnode=(L1*)malloc(sizeof(L1));
    printf("ENTER ELEMENT OF LL1:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
     head=newnode;
     tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void INSERT()
{
    int value;
    NEWNODE=(L2*)malloc(sizeof(L2));
    printf("ENTER ELEMENT OF LL2:");
    scanf("%d",&value);
    NEWNODE->data=value;
    NEWNODE->next=NULL;
    if(HEAD==NULL)
    {
        HEAD=NEWNODE;
        TAIL=NEWNODE;
    }
    else
    {
        TAIL->next=NEWNODE;
        TAIL=NEWNODE;
    }
}

