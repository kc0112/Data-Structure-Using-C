#include<stdio.h>
void push(char);
char pop(void);
int sign(char);
int precedence(char);
int top=-1;int stack[100],c=1;

struct tree
{
    int data;
    struct tree*left,*right;
}*root,*temp,*op1,*op2;

typedef struct tree tree;
tree* insert(tree*,char);
int main()
{
  int  i=0,j=0,k=0;
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
  printf("PRINTING POSTFIX EXPRESSION\n");
  puts(POSTFIX);

  while(POSTFIX[k]!='\0')
  {
      item=POSTFIX[k];
      if(item>='A'&&item<='Z'||item>='a'&&item<='z')
      {
        push(item);
      }
      else if(sign(item)==1)
      {
          root=insert(root,item);
          op1=pop();
          op2=pop();
          root=insert(root,op1);
          root=insert(root,op2);
          push(root);     //how to push a address its getting o=pushes as character
      }

      k++;

  }
     root=pop();
    display(root);
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

void display(tree* root)
{

    if(root==NULL)
        return;
        display(root->left);
    printf("%c ",root->data);
        display(root->right);
}

tree* insert(tree* root,char value)
{
  if (root==NULL)
    {
        root=(tree*)malloc(sizeof(tree));
        root->data=value;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        if(c%2==0)
            root->left=insert(root->left,value);
        else
            root->right=insert(root->right,value);
    }
    return root;
}



