#include<stdio.h>
struct node
{
    int data;
    struct node* next;

}*head,*tail,*temp,*new,*slow,*fast;


typedef struct node node;

int HasCycle(node*);
node* insert(int);
 int main()
   {
       head=insert(40);
       head=insert(50);
       head=insert(10);
       head=insert(20);
       head=insert(90);
       head=insert(60);
       head=insert(70);
       head=insert(80);

tail->next=head->next->next;
        int res=HasCycle(head);
        if(res==1)
            printf("has cycle");
        else
            printf("no cycle");

   }

int HasCycle(node* head)
        {
         if (head == NULL)
        return 0;
         slow=head;
        fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return 1;
            }
        }
        return 0;

       }

       node* insert(int value)
    {
        new=(struct node*)malloc(sizeof(struct node));
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
        return (head);
    }
