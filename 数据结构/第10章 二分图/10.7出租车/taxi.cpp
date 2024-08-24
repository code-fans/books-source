//出租车
#include<bits/stdc++.h>
using namespace std;

int n,t;
struct node
{
  int time1,time2;
  int x1,y1,x2,y2;
} A[501];
int G[501][501],match[501],visit[501],dfscnt;

bool dfs(int root)
{
  for(int i=1; i<=n; i++)
    if(G[root][i])
      if(visit[i]!=dfscnt)
      {
        visit[i]=dfscnt;
        if(!match[i]||dfs(match[i]))
        {
          match[i]=root;
          return true;
        }
      }
  return false;
}

int D(int x1,int y1,int x2,int y2)
{
  return abs(x2-x1)+abs(y2-y1);
}

int main()
{
  freopen("taxi.in","r",stdin);
  freopen("taxi.out","w",stdout);
  scanf("%d",&t);
  while(t--)
  {
    memset(G,0,sizeof(G));
    memset(visit,0,sizeof(visit));
    memset(match,0,sizeof(match));
    scanf("%d",&n);
    int hour,min;
    for(int i=1; i<=n; i++)
    {
      scanf("%d:%d",&hour,&min);
      A[i].time1=hour*60+min;
      scanf("%d%d%d%d",&A[i].x1,&A[i].y1,&A[i].x2,&A[i].y2);
      A[i].time2=A[i].time1+D(A[i].x1,A[i].y1,A[i].x2,A[i].y2);
    }
    for(int i=1; i<=n; i++)                       //构图，能接下个任务的连边
      for(int j=i; j<=n; j++)
        if(A[i].time2+D(A[i].x2,A[i].y2,A[j].x1,A[j].y1)<A[j].time1)
          G[i][j]=1;
    int ans=0;
    dfscnt=0;
    for(int i=1; i<=n; i++)
    {
      dfscnt++;
      ans+=dfs(i);
    }
    printf("%d\n",n-ans);
  }
}

