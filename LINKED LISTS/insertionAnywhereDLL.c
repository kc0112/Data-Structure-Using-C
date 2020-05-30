#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    } *head,*tail,*temp,*new;

 main()

   {
       int ch,value,pos,i;
       do
    {
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        new->data=value;
        new->next=NULL;
        new->prev=NULL;
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
        printf("Y=continue,N=exit\n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch=='Y');

    //insertion at ANYWHERE

   fflush(stdin);

    printf("enter the value to insert");
    scanf("%d",&value);
    printf("enter position");
    scanf("%d",&pos);
    new=(struct node*)malloc(sizeof(struct node));
    temp=head;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }

    new->data=value;
    new->prev=temp;
    new->next=temp->next;
    temp->next=new;

    //PRINTING

   temp=head;
    while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }

}



