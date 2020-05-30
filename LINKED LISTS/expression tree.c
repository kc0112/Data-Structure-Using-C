#include<stdio.h>
#include<stdlib.h>
void push(char);
char pop(void);
int sign(char);
void expression(char POSTFIX[]);
int precedence(char);
int top=-1;int stack[100];

struct node
{
    int data;
    struct node* left,*right;
}*root;
int main()
{
  int  i=0,j=0;
  char item,temp;
  char POSTFIX[60];
  char INFIX[60];

      //Input expression
      printf("\n Enter the expression:");
      gets(INFIX);

      //push and pop one by one
      while(INFIX[i]!='\0')
      {
          item=INFIX[i];

          if( item=='(' )
           {
            push(item);
           }

          else if(item>='A'&&item<='Z'||item>='a'&&item<='z')
            {
                POSTFIX[j]=item;
                j++;
            }

          else if(sign(item)==1)
          {

                  temp= pop();
                  while(sign(temp)==1&&precedence(temp)>=precedence(item))
                  {
                      POSTFIX[j]=temp;
                      j++;
                      temp=pop();
                  }
                  push(temp);
                  push(item);

          }

          else if(item==')')

          {
              temp=pop();
              while(temp!='(')
              {
                POSTFIX[j]=temp;
                j++;
                temp=pop();
              }
          }

          else
           {
               printf("INVALID EXP");
           }
          i++;
      }

  while(top>-1)
  {
      POSTFIX[j]=pop();
      j++;
  }
  POSTFIX[j]='\0';
  puts(POSTFIX);
  expression(POSTFIX);
  return 0;
}



//push
void push(char item)
{
            top++;
        stack[top]=item;
}


//pop
char pop(void)
{
    char item;
    item=stack[top];
    top--;
    return (item);

}


//operator
int sign(char symbol)
{
    if(symbol=='+'||symbol=='/'||symbol=='*'||symbol=='-')
        return 1;
    else
        return 0;
}


//priority check
int precedence(char symbol)
{
    if( symbol=='*'||symbol=='/')
        return 2;
    else
        return 1;
}

void expression (char POSTFIX[])
{

    int i=0;
    char item;
    while(POSTFIX[i]!='\0')
    {

        item=POSTFIX[i];

        if(item>='A'&&item<='Z'||item>='a'&&item<='z')
        {
            push(item);
        }
        else
        {
            root=(struct node*)malloc(sizeof(struct node));
             root->data=item;
            root->left=pop();
            root->right=pop();

        }
        i++;
    }
    printf("%c",stack[top]);

}



