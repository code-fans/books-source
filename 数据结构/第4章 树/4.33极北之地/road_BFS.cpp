//极北之地--BFS算法
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;

int head[MAXN],visit[MAXN],dist[MAXN];
int node=1,ans,k;
struct Edge
{
  int v,len;
  int next;
} edge[MAXN<<2];

void AddEdge(int u,int v,int l)        //使用前向星表示法，请参见第五章
{
  edge[k].v=v;
  edge[k].len=l;
  edge[k].next=head[u];
  head[u]=k++;
}

void Bfs(int p)
{
  queue<int>q;
  visit[p]=1;
  q.push(p);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
      int v=edge[i].v;
      if(visit[v]==0)
      {
        dist[v]=dist[u]+edge[i].len;
        visit[v]=1;
        q.push(v);
        if(dist[v]>ans)
        {
          ans=dist[v];
          node=v;
        }
      }
    }
  }
}

int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int l,r,len;
  memset(head,-1,sizeof(head));
  while(scanf("%d%d%d",&l,&r,&len)!=EOF)
  {
    AddEdge(l,r,len);
    AddEdge(r,l,len);
  }
  for(int i=1; i<=2; i++)
  {
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    ans=0;
    Bfs(node);
  }
  printf("%d\n",ans);
  return 0;
}

