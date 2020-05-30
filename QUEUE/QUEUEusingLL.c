
#include<stdio.h>
void enqueue(void);
void dequeue(void);
void display(void);

struct node
{
    int data;
    struct node *next;
}*new,*temp,*rear,*front;


int main()
{
int choice;
    front=NULL;
    rear=NULL;
    printf("\n\t QUEUE OPERATIONS USING LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
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

void enqueue()
{
    int ele;
    new=(struct node*)malloc(sizeof(struct node));
    printf("ENTER ELEMENT TO BE ENQUEUED:");
    scanf("%d",&ele);
    new->data=ele;
    new->next=NULL;
    if(rear==NULL)
    {
        front=new;
        rear=new;
    }
    else
        rear->next=new;
    rear=new;
}

void dequeue()
{
    if(front==NULL)
    printf("QUEUE IS EMPTY");
    else
    {
        temp=front;
        printf("%d IS DELETED",temp->data);
        front=front->next;
        free(temp);
    }

}

void display()
{
    temp=front;
    if(front==NULL)
        printf("EMPTY QUEUE");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
    temp=temp->next;
    }
}
