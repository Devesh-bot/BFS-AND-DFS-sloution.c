/* BFS and DFS*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<string.h>
#define size 40
int q[size],top=-1,front=-1,rear=-1,a[size][size],visited[size],stack[size];
int dequeue();
void enqueue(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();

void main()
{
int n,i,s,ch,j;
char c,dummy;
printf("ENTER THE NUMBER VERTICES:\n");
scanf("%d",&n);
printf("ENTER 1 IF EDGE BETWEEN TWO NODE ELSE ENTER 0:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{

scanf("%d",&a[i][j]);
}
}
printf("THE ADJACENCY MATRIX IS\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}

do
{
for(i=1;i<=n;i++)
visited[i]=0;
printf("\nMENU");
printf("\n1.B.F.S");
printf("\n2.D.F.S");
printf("\nENTER YOUR CHOICE");
scanf("%d",&ch);
printf("ENTER THE SOURCE VERTEX :\n");
scanf("%d",&s);

switch(ch)
{
case 1:bfs(s,n);
break;
case 2:
dfs(s,n);
break;
}
printf("\nDO U WANT TOCONTINUE(Y/N) ? ");
scanf("%c",&dummy);
scanf("%c",&c);
}while((c=='y')||(c=='Y'));
}//main exit

void bfs(int s,int n)
{
int p,i;
enqueue(s);
visited[s]=1;
p=dequeue();
if(p!=0)
printf("%d",p);
while(p!=0)
{
for(i=1;i<=n;i++)
if((a[p][i]!=0)&&(visited[i]==0))
{
enqueue(i);
visited[i]=1;
}
p=dequeue();
if(p!=0)
printf("%d",p);
}
for(i=1;i<=n;i++)
if(visited[i]==0)
bfs(i,n);
}

void enqueue(int item)
{
if(rear==size-1)
printf("QUEUE FULL");
else
{
if(rear==-1)
{
q[++rear]=item;
front++;
}
else
q[++rear]=item;
}
}
int dequeue()
{
int k;
if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}

void dfs(int s,int n)
{
int i,k;
push(s);
visited[s]=1;
k=pop();
if(k!=0)
printf("%d",k);
while(k!=0)
{
for(i=1;i<=n;i++)
if((a[k][i]!=0)&&(visited[i]==0))
{
push(i);
visited[i]=1;
}
k=pop();
if(k!=0)
printf("%d",k);
}
for(i=1;i<=n;i++)
if(visited[i]==0)
dfs(i,n);
}

void push(int item)
{
if(top==size-1)
printf("Stack overflow");
else
stack[++top]=item ;
}

int pop()
{
int k ;
if(top==-1)
return(0);
else
{
k=stack[top--];
return(k);
}
}
