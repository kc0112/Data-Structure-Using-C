
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
       int ch,value,i,pos;
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

    //deletion at anywhere

      printf("enter position:");
      scanf("%d",&pos);
     temp=head;
     for(i=1;i<pos-1;i++)
     {
         temp=temp->next;
     }
     temp->next=temp->next->next;
     temp->next->prev=temp;


    //PRINTING

   temp=head;
    while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }

}




