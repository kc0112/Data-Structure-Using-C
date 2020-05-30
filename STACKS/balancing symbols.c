#include<stdio.h>
void push(char);
char pop(void);
int evaluate (char,char);
int stack[20],top=-1,res;


int main()
{
 char INFIX[50],item,temp;
 int i=0;

 printf("ENTER EXPRESSION:");
 gets(INFIX);

 while(INFIX[i]!='\0')
 {
     item=INFIX[i];

     if(item=='('||item=='['||item=='{')
            {
                push(item);
            }

    else if(item==')'||item=='}'||item==']')
    {
        temp=pop();
        res=evaluate(temp,item);
        if(res==0)
        {
            printf("IMBALANCED EXPRESSION\n");
            break;
        }
    }
    i++;
 }
 if(res==1)
    printf("EXPRESSION BALANCED");
}

void push(char item)
{
    top++;
    stack[top]=item;
}

char pop()
{
    char temp;
    temp=stack[top];
    top--;
    return(temp);
}

int evaluate (char temp,char item)
{
    if(temp=='{'&&item=='}')
        return 1;
    else if(temp=='['&&item==']')
        return 1;
        else if  (temp=='('&&item==')')
        return 1;
        else return 0;
}
