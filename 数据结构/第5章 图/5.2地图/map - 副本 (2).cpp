//地图—优先队列模拟Dijkstra堆优化
#include <bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;

struct Edge
{
  int v,w,nxt;
} e[500100];
int head[1510],cnt;

inline void AddEdge(int u,int v,int w)
{
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].nxt=head[u];
  head[u]=cnt;
}

int n,m;
int dis[1510];

struct node   //定义堆节点
{
  int u,d;
  bool operator <(const node& b) const
  {
    return d>b.d;
  }
};

inline void Dijkstra()
{
  memset(dis,127/2,sizeof(dis));
  dis[1]=0;
  priority_queue<node> Q;       //优先队列模拟堆
  Q.push((node)
  {
    1,0
  });
  while (!Q.empty())
  {
    int u=Q.top().u;
    int d=Q.top().d;
    Q.pop();
    if (d!=dis[u])              //删除原结点不方便，故以此判断是否被删除过
      continue;
    for (int i=head[u]; i; i=e[i].nxt)
    {
      int v=e[i].v,w=e[i].w;
      if (dis[u]+w<dis[v])      //松驰操作
      {
        dis[v]=dis[u]+w;
        Q.push((node)
        {
          v,dis[v]
        });
      }
    }
  }
}

int main()
{
  //freopen("map.in","r",stdin);
  //freopen("map.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)                //读入图
    for(int j=1; j<=n; j++)
    {
      cin>>m;
      if(m!=-1)
        AddEdge(i,j,m);
    }
  Dijkstra();
  for (int i=1; i<=n; i++)
    printf("%d\n",dis[i]);
  return 0;
}
