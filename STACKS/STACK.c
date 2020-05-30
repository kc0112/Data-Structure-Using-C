#include<stdio.h>
int stack[100],choice,size,top,element,i;
void push(void);
void pop(void);
void display(void);
int main()
{

    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&size);
    printf("\n\t STACK OPERATIONS USING ARRAY");
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
    printf("ENTER THE ELEMENT TO BE PUSHED:");
    scanf("%d",&element);
    if(top==size-1)
        printf("OVERFLOW !!!");
    else
    {
        top++;
        stack[top]=element;
    }
}

void pop()
{
    if(top==-1)
        printf("UNDERFLOW !!!");
    else
    {
        element=stack[top];
        printf("ELEMENT IS DELETED !");
        top--;
    }
}

void display()
{
    if(top!=-1)
    {
        for(i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
    else
        printf("EMPTY STACK !!!");
}


