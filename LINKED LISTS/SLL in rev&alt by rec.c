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
    void display(node*);
    void reverse (node*);
    void func2(node*);

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
       display(head);
       printf("\nreverse order:");
       reverse(head);
       printf("\nalternate straight n reverse order:");
       func2(head);
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

    void display(node* head)
    {
        temp=head;
       while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }
    }

    void reverse (node*head)
    {
        if(head==NULL)
            return;
        else
            reverse(head->next);
        printf("%d ",head->data);
    }


    void func2(node* start)
{
  if(start == NULL)
    return;
  printf("%d ", start->data);

  if(start->next != NULL )
    func2(start->next->next);
  printf("%d ", start->data);
}
