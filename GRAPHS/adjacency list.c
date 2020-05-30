#include<stdio.h>
#include<stdlib.h>
void display(int );

struct vertex
{
    int id;
    struct vertex *edge [10];
}node[10];

int main()
{
    int i,j,n;
    char ch;
    i=j=n=0;
    printf("ENTER THE NO. OF VERTICES IN GRAPH:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        node[i].id=i;
        for(j=1;j<=n;j++)
        {
            fflush(stdin);
            printf("EDGE FROM %d TO %d ?(y/n):",i,j);
            scanf("%c",&ch);
            if(ch=='y')
                node[i].edge[j]=&node[j];
            else
                node[i].edge[j]=NULL;
        }
        printf("\n");
    }
      printf("\n");
    display(n);
}

void display(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
           printf("EDGE OF NODE %d ARE:",i);
            for(j=1;j<=n;j++)
        {
            if(node[i].edge[j]==NULL)
                continue;
           printf("\t%d",node[i].edge[j]->id);
        }
        printf("\n");
    }
}
