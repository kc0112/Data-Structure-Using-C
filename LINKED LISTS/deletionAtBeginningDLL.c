
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
       int ch,value;
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

    //DELETION at BEGINNING



    head=head->next;
    head->prev=NULL;


    //PRINTING

   temp=head;
    while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }

}




