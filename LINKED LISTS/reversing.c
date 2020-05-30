#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
   }*head,*tail,*temp,*current,*prev=NULL,*new;

    main()
   {
       int ch,value,i,pos;
       do
    {
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
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
            tail=new;
        }
        printf("Y=continue,N=exit\n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch=='Y');

   //reversing

   current=head;
   while(current!=NULL)
   {
     temp=current->next;
     current->next=prev;
     prev=current;
     current=temp;
   }
  head=prev;

    //printing

       temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}





