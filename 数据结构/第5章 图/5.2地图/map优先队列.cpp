//地图—优先队列模拟Dijkstra堆优化
#include <bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct node
{
  int w,to,nxt;
} e[5001000];                     //注意结构体数组要足够大
int n,m,cnt,head[1510],dis[1510];
bool vis[1510];

void AddEdge(int u,int v,int w)
{
  e[++cnt].to=v;
  e[cnt].w=w;
  e[cnt].nxt=head[u];
  head[u]=cnt;
}

void Dijkstra(int start)
{
  memset(dis,127/2,sizeof(dis));
  q.push(make_pair(0,start));
  dis[start]=0;
  while(!q.empty())
  {
    int Now=q.top().second;
    q.pop();
    if(vis[Now])
      continue;
    vis[Now]=1;
    for(int i=head[Now]; i; i=e[i].nxt)
      if(dis[Now]+e[i].w<dis[e[i].to])
      {
        dis[e[i].to]=dis[Now]+e[i].w;           //(start,Now)+(Now,to)
        q.push(make_pair(dis[e[i].to],e[i].to));
      }
  }
}

int main()
{
  freopen("map.in","r",stdin);
  freopen("map.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)                //读入图
    for(int j=1; j<=n; j++)
    {
      cin>>m;
      if(m!=-1)
        AddEdge(i,j,m);
    }
  Dijkstra(1);
  for(int i=1; i<=n; i++)
    printf("%d\n",dis[i]);
  return 0;
}
