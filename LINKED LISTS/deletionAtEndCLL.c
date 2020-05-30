#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
   }*head,*tail,*temp,*new;

    main()
   {
       int ch,value;
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

    //deletion at end

     temp=head;
     while(temp->next!=tail)
     {
         temp=temp->next;
     }
     tail->next=NULL;
     temp->next=head;
     tail=temp;

    //printing

        temp=head;
    while(temp->next!=head)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}



