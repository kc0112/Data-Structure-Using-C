
#include <stdio.h>
#include <stdlib.h>
    struct node
    {
        int data;
        struct node *next;
    } *head,*tail,*temp,*new;

 main()

   {int ch,value,pos,i;
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

    //insertion at anywhere

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
    new->next=temp->next;
    temp->next=new;

    //display
   temp=head;
    while(temp->next!=head)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

}



