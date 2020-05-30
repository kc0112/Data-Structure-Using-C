#include<stdio.h>
int queue[100],choice,size,front,rear,element,i;
void enqueue(void);
void dequeue(void);
void display(void);
int main()
{

    front=-1;
    rear=-1;
    printf("\n Enter the size of QUEUE[MAX=100]:");
    scanf("%d",&size);
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
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

    if(rear==size-1)
        printf("OVERFLOW !!!");
    else
    {
        printf("ENTER THE ELEMENT TO BE ENQUEUED:");
        scanf("%d",&element);
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=element;
    }
}

void dequeue()
{
    if(rear==-1||front>rear)
        printf("UNDERFLOW !!!");
    else
    {
        element=queue[front];
        printf("ELEMENT IS DELETED !");
        front++;
    }
}

void display()
{
    if(rear==-1||front>rear)
        printf("EMPTY QUEUE !!!");
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}



