#include<stdlib.h>
#include<stdio.h>

struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    } *head,*tail,*temp,*new,*y;

    typedef struct node node;
    node*insert (int);
    node* del (node*);


    int main()

   {
       head=insert(40);
       head=insert(50);
       head=insert(50);
       head=insert(60);
       head=insert(60);
       head=insert(60);
       head=insert(70);
       head=insert(80);

       head=del(head);

       temp=head;
       while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
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



    node* del(node*head)
    {
        temp=head;
        while(temp->next!=NULL)
        {
          if(temp->data==temp->next->data)
        {
            y=temp->next;
            temp->next=temp->next->next;
             free(y);
        }
        else
        temp=temp->next;
        }

        return (head);
    }
