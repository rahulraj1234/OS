#include<stdio.h>
int main()
{
    int a[20],initial,final,n,res=0,head_pos;
    printf("Enter the no of requests");
    scanf("%d",&n);
    printf("Enter the requests in order");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the current head position");
    scanf("%d",&head_pos);
    initial=head_pos;
    for(int i=0;i<n;i++)
    {
        final=a[i];
        if(final>initial)
            res+=final-initial;
        else
            res+=initial-final;
        initial=final;
    }
    printf("Total head movements=%d cylinders",res);
}