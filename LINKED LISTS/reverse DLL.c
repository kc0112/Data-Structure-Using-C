#include<stdio.h>
struct node
{
    int data;
    struct node* next,*prev;
}*head,*tail,*temp,*newn,*cur,*back=NULL;
typedef struct node node;
node* insert(int);
void rev(node*);

int main()
{
    head=insert(40);
    head=insert(30);
    head=insert(10);
    head=insert(50);
    head=insert(60);
    display(head);
    printf("\n");
    rev(head);

}

node* insert(int value)
{
 newn=(node*)malloc(sizeof(node));
 newn->data=value;
 newn->next=NULL;
 newn->prev=NULL;
 if(head==NULL)
 {
     head=newn;
     tail=newn;
 }
 else
 {
     tail->next=newn;
     newn->prev=tail;
     tail=newn;
 }
 return(head);
}

void rev (node* head)
{

        cur=head;
        while(cur!=NULL)
        {
        temp=cur->next;
        cur->prev=cur->next;
        cur->next=back;

        back=cur;
        cur=temp;
        }

        head=back;
        display(head);
}

void display(node*head)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

