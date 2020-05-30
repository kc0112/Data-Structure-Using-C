#include<stdio.h>
int main()
{
    int i=0,a[50],j,k=1;
        printf("ENTER THE ROOT NODE:");
        scanf("%d",&a[i]);

       while(i>=0)
        {
        printf("ENTER THE LEFT CHILD OF %d:",a[i]);
        scanf("%d",&a[2*i+1]);
        if(a[2*i+1]==-1)
            break;
        k++;
        printf("ENTER THE RIGHT CHILD of %d:",a[i]);
        scanf("%d",&a[2*i+2]);
        i++;k++;
        }


    for(j=0;j<k;j++)
    {
        printf("%d ",a[j]);
    }
}
