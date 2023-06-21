#include<stdio.h>
int main()
{
    int a[20],initial,final,n,res=0,head_pos,search[20];
    int diff,min=10000,loc=-1,k=0;
    printf("Enter the no of requests");
    scanf("%d",&n);
    printf("Enter the requests in order");
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter the current head position");
    scanf("%d",&head_pos);
    initial=head_pos;
    while(k!=n)
    {
        for(int i=0; i<n; i++)
        {
            final=a[i];
            if(final>initial)
                diff=final-initial;
            else
                diff=initial-final;
            if(diff<min && search[i]!=1)
            {
                min=diff;
                loc=i;
            }
        }
        if(loc!=-1)
        {
            final=a[loc];
            search[loc]=1;
            if(final>initial)
                res+=final-initial;
            else
                res+=initial-final;
            initial=final;
            k++;
        }
        min=10000;
    }
    printf("Total head movements=%d cylinders",res);
}