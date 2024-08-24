//单源最短路径—SPFA算法
#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define maxn 10005
#define maxm 500005

int n,m,s,tot,dis[maxn],head[maxn];
bool vis[maxn];
queue<int> q;
struct Edge
{
  int next,to,w;
} h[maxm];

void AddEdge(int u,int v,int w)
{
  h[++tot].next=head[u];
  h[tot].to=v;
  h[tot].w=w;
  head[u]=tot;
}

void SPFA()
{
  for(int i=1; i<=n; i++)
    dis[i]=(INF>>1);
  q.push(s);
  dis[s]=0;
  vis[s]=1;
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=head[u]; i; i=h[i].next) //寻找与u相连的边
    {
      int v=h[i].to;
      if(dis[v]>dis[u]+h[i].w)
      {
        dis[v]=dis[u]+h[i].w;
        if(!vis[v])
        {
          vis[v]=1;
          q.push(v);
        }
      }
    }
  }
}

int main()
{
  freopen("path.in","r",stdin);
  freopen("path.out","w",stdout);
  cin>>n>>m>>s;
  for(int i=1,u,v,w; i<=m; i++)
  {
    cin>>u>>v>>w;
    AddEdge(u,v,w);
  }
  SPFA();
  for(int i=1; i<=n; i++)
    printf("%d%c",dis[i]>=(INF>>1)?INF:dis[i],i==n?'\n':' ');
  return 0;
}
