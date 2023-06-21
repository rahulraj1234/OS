#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node *link;
}*GPTR[100];
int q[20],front=0,rear=0,visit[20],n;
void enqueue(int a)
{
    if(front==0 && rear==0)
    {
        q[++rear]=a;
        front++;
    }
    else
        q[++rear]=a;
}
int dequeue()
{
    int item;
    if(front==rear)
    {
      item=q[front];
      front=0,rear=0;
    }
    else  
        item=q[front++];
    return item;
}
bool search(int *p,int item)
{
    int flag=0,i=0;
    while(i<n)
    {
        if(*p==item)
        {
            flag=1;
            break;
        }
        p++;
        i++;
    }
    if(flag==1)
        return true;
    else
        return false;
}
void BFS(int v)
{
    int u,i=0;
    struct node *ptr;
    u=v;
    enqueue(u);
    while(front!=0 && rear!=0)
    {
        u=dequeue();
        if(search(visit,u)==false)
        {
            visit[i]=u;
            i++;
            ptr=GPTR[u];
            while(ptr!=NULL)
            {
                enqueue(ptr->vertex);
                ptr=ptr->link;
            }
        }
    }
    printf("BFS traversal\n");
    for(int j=0; j<n; j++)
        printf("%d\t",visit[j]);
}
int main()
{
    int vt,vn,av,sv,i;
    printf("Enter the no of vertices in the graph");
    scanf("%d",&n);
    for(int i=0; i<60; i++)
        GPTR[i]=NULL;
    printf("Enter first vertex");
    do
    {
        scanf("%d",&vt);
        printf("Enter the no of adjacent vertices of %d\n",vt);
        scanf("%d",&vn);
        for(int k=0; k<vn; k++)
        {
            struct node *p=(struct node *)malloc(sizeof(struct node));
            printf("Enter adjacent vertex");
            scanf("%d",&av);
            p->vertex=av;
            p->link=NULL;
            if(GPTR[vt]==NULL)
                GPTR[vt]=p;
            else
            {
                struct node *temp=GPTR[vt];
                while(temp->link!=NULL)
                    temp=temp->link;
                p->link=NULL;
                temp->link=p;
            }
        }
        if(i!=n-1)
            printf("Enter next vertex");
        i++;
    } while(i<n);
    printf("Enter the starting vertex for traversal");
    scanf("%d",&sv);
    BFS(sv);
}

/*
                OUTPUT

        Enter the no of vertices in the tree6
        Enter first vertex1
        Enter the no of adjacent vertices of 1
        3
        Enter adjacent vertex2
        Enter adjacent vertex3
        Enter adjacent vertex4
        Enter next vertex2
        Enter the no of adjacent vertices of 2
        2
        Enter adjacent vertex1
        Enter adjacent vertex5
        Enter next vertex3
        Enter the no of adjacent vertices of 3
        2
        Enter adjacent vertex1
        Enter adjacent vertex5
        Enter next vertex4
        Enter the no of adjacent vertices of 4
        3
        Enter adjacent vertex1
        Enter adjacent vertex5
        Enter adjacent vertex6
        Enter next vertex5
        Enter the no of adjacent vertices of 5
        4
        Enter adjacent vertex2
        Enter adjacent vertex3
        Enter adjacent vertex4
        Enter adjacent vertex6
        Enter next vertex6
        Enter the no of adjacent vertices of 6
        2
        Enter adjacent vertex5
        Enter adjacent vertex4
        Enter the starting vertex3
        DFS traversal
        3       5       6       4       1       2
*/

    