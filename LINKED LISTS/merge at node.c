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
struct L3
{
    int data;
    struct L3* next;
}*sir,*puch,*newn,*s,*t;

typedef struct L2 L2;
typedef struct L1 L1;
typedef struct L3 L3;

L1* insert(int);
L2* INSERT(int);
L3* add(int);

int main()
{
       head=insert(10);
       head=insert(20);
       head=insert(30);

       HEAD=INSERT(40);
       HEAD=INSERT(50);
       HEAD=INSERT(60);

       sir=add(70);
       sir=add(80);


       tail->next=sir;
       TAIL->next=sir;

       temp=head;
       TEMP=HEAD;
       while(temp->next!=TEMP->next)
       {
         temp=temp->next;
         TEMP=TEMP->next;
       }
     printf("%d",temp->next->data);
}

L1* insert(int value)
{

    newnode=(L1*)malloc(sizeof(L1));

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
    return head;
}

L2* INSERT(int value)
{

    NEWNODE=(L2*)malloc(sizeof(L2));

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
    return HEAD;
}
L3* add(int value)
{
    newn=(L3*)malloc(sizeof(L3));
    newn->data=value;
    newn->next=NULL;
    if(sir==NULL)
    {
     sir=newn;
     puch=newn;
    }
    else
    {
        puch->next=newn;
        puch=newn;
    }
    return (sir);
}




