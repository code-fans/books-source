//火星机器人
#include<bits/stdc++.h>
using namespace std;
#define N 510
int G[N][N],Link[N];
bool vis[N];
int n,m,u,v;

bool DFS(int u)
{
  for(int v=0; v<n; v++)
    if(G[u][v]&&!vis[v])
    {
      vis[v]=true;
      if(Link[v]==-1||DFS(Link[v]))
      {
        Link[v]=u;
        return true;
      }
    }
  return false;
}

void Floyd(int n)                              //求图的闭包
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(G[i][j]==0)
        for(int k=0; k<n; k++)
          if(G[i][k]==1 && G[k][j]==1)
          {
            G[i][j]=1;
            break;
          }
}

int main()
{
  //freopen("robot.in","r",stdin);
  //freopen("robot.out","w",stdout);
  while(~scanf("%d%d",&n,&m) && (n||m))
  {
    memset(G,0,sizeof(G));
    memset(Link,-1,sizeof(Link));
    while(m--)
    {
      scanf("%d%d",&u,&v);
      u--;
      v--;
      G[u][v]=1;
    }
    Floyd(n);
    int ans=0;
    for(int u=0; u<n; u++)
    {
      memset(vis,false,sizeof(vis));
      ans+=DFS(u);
    }
    printf("%d\n",n-ans);
  }
  return 0;
}

