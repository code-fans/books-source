//前向星的深度优先搜索
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int Cnt;

struct node
{
  int to;
  int next;
} edge[maxn];
int Head[maxn];
bool vis[maxn];

void AddEdge(int u,int v)
{
  edge[++Cnt].to=v;
  edge[Cnt].next=Head[u];
  Head[u]=Cnt;
}

void Dfs(int x)
{
  vis[x]=1;                                 //标记x结点被访问
  cout<<x<<"\n";
  for(int k=Head[x]; k!=-1; k=edge[k].next)
    if(!vis[edge[k].to])                    //如果没有被访问过
      Dfs(edge[k].to);                      //继续深度搜索
}

int main()
{
  freopen("dfs.in","r",stdin);
  freopen("dfs.out","w",stdout);
  int n,m,u,v;
  cin>>n>>m;
  memset(Head,-1,sizeof(Head));
  for(int i=1; i<=m; i++)
  {
    cin>>u>>v;
    AddEdge(u,v);                           //无向图添加两次边
    AddEdge(v,u);
  }
  Dfs(1);                                   //从结点1开始深搜
  return 0;
}

