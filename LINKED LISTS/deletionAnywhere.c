#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
   }*head,*tail,*temp,*new;

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

    //deletion at anywhere
      printf("enter position:");
      scanf("%d",&pos);
     temp=head;
     for(i=1;i<pos-1;i++)
     {
         temp=temp->next;
     }
     temp->next=temp->next->next;

    //printing

       temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}




