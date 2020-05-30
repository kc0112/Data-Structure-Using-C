#include<stdio.h>
void push(void);
void pop(void);
void display(void);

struct node
{
    int data;
     struct node *next;
}*new,*temp,*top;

int main()
{

    int choice;
    top=NULL;

    printf("\n\t STACK OPERATIONS USING LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

     do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(choice!=4);
    return 0;
}

   void push()
{
    int ele;
    new=(struct node*)malloc(sizeof(struct node));
    printf("ENTER THE ELEMENT TO BE PUSHED:");
    scanf("%d",&ele);
    if(top==NULL)
    {
        new->data=ele;
        new->next=NULL;
        top=new;
    }
    else
    {
        new->data=ele;
        new->next=top;
        top=new;
    }

}

void pop()
{
    int ele;
    if(top==NULL)
        printf("STACK IS EMPTY\n");
    else
    {
        temp=top;
        ele=top->data;
        printf("element %d is deleted",ele);
        top=top->next;
        free(temp);
    }
}

void display()

{
    if(top==NULL)
    printf("STACK IS EMPTY\n");
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

