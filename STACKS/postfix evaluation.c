#include<stdio.h>
void push(int);
int pop(void);
int top=-1;
char res;
int stack[100];
int main()
{
 char POSTFIX[50],item;
 int i=0,m,value,op1,op2;

 printf("INPUT EXPRESSION:");
 gets(POSTFIX);

 while(POSTFIX[i]!='\0')
 {

     item=POSTFIX[i];
     if(item>='a'&&item<='z'||item<='A'&&item>='Z')
        {
            printf("ENTER THE VALUE OF %c:",item);
            scanf("%d",&m);
          push(m);
        }
     else
     {
        op1=pop();
        op2=pop();
        switch (item)
       {
        case'+':res=op2+op1;
         push(res);
        break;
        case'-':res=op2-op1;
         push(res);
        break;
        case'*':res=op2*op1;
         push(res);
        break;
        case'/':res=op2/op1;
         push(res);
       }

     }
     i++;
 }
 res=pop();
 printf("result is %d",res);
}

void push(int value)
{
    top++;
    stack[top]=value;
}

int pop()
{
    int temp;
    temp=stack[top];
    top--;
    return temp;
}
