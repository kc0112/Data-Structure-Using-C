#include <stdio.h>
#include <stdlib.h>

    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    } *head,*tail,*temp,*new;

    typedef struct node node;
    node*insert (int);

    int main()

   {
       head=insert(40);
       head=insert(50);
       head=insert(10);
       head=insert(20);
       head=insert(30);
       head=insert(60);
       head=insert(70);
       head=insert(80);

       head->prev=NULL;
       head=tail;
       temp=head;
       while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->prev;
    }
}

    node* insert(int value)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->prev=NULL;
        new->data=value;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            new->prev=tail;
            tail=new;
        }
        return (head);
    }

