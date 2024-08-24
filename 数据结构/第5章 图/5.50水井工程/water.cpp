#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int inf=INT_MAX;

int n,X,Y,Z,root;
int id[N],pre[N],in[N],vis[N];
struct node
{
  int x,y,z;
} E[N];
struct Edge
{
  int f,t,cost;
} edge[N*N];
int tot;
void add(int a,int b,int c)
{
  edge[tot].f=a;
  edge[tot].t=b;
  edge[tot++].cost=c;
}

void build_map()
{
  int i,t,temp,b;
  tot=0;
  for(i=1; i<=n; i++)
  {
    add(0,i,X*E[i].z);
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&b);
      if(b==i)	continue;
      temp=abs(E[i].x-E[b].x)+abs(E[i].y-E[b].y)+abs(E[i].z-E[b].z);
      temp*=Y;
      if(E[b].z>E[i].z)	temp+=Z;
      add(i,b,temp);
    }
  }
}

int solve()
{
  int i,u,v,cnt,ans=0,nv=n+1;
  while(1)
  {
    //找每个node的最小入边值
    for(i=0; i<nv; i++)
    {
      in[i]=inf;
      id[i]=-1;
      vis[i]=-1;
    }
    for(i=0; i<tot; i++)
    {
      u=edge[i].f;
      v=edge[i].t;
      if(edge[i].cost>=in[v] || u==v)	continue;
      in[v]=edge[i].cost;
      pre[v]=u;
    }
    in[root]=0;
    pre[root]=root;
    //判断是否有断 && 更新ans(此题必定有解，所以对于这个题，是肯定不会有断的。)
    for(i=0; i<nv; i++)
    {
      ans+=in[i];
      if(in[i]==inf)	return -1;
    }
    //重新构图
    cnt=0;
    for(i=0; i<nv; i++)
    {
      v=i;
      while(vis[v]==-1)
      {
        vis[v]=i;
        v=pre[v];
      }
      if(vis[v]!=i || v==root)	continue;
      for(u=pre[v]; u!=v; u=pre[u])	id[u]=cnt;
      id[v]=cnt++;
    }
    if(!cnt)	break;
    for(i=0; i<nv; i++)	if(id[i]==-1)	id[i]=cnt++;
    //更新边
    for(i=0; i<tot; i++)
    {
      u=edge[i].f;
      v=edge[i].t;
      edge[i].f=id[u];
      edge[i].t=id[v];
      edge[i].cost-=in[v];
    }
    //next
    nv=cnt;
    root=id[root];
  }
  return ans;
}
int main()
{
  freopen("water.in","r",stdin);
  freopen("water.out","w",stdout);
  while(scanf("%d%d%d%d",&n,&X,&Y,&Z),n||X||Y||Z)
  {
    for(int i=1; i<=n; i++)	scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].z);
    build_map();
    root=0;
    printf("%d\n",solve());
  }
  return 0;
}

