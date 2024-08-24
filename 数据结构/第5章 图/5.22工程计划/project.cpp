//工程计划
#include <bits/stdc++.h>
using namespace std;
const int Ns=20005;
const int Ms=20005;

int N,M,im[Ns],vmin[Ns];
int p[Ns],cnt;

struct edge
{
  int v,w,next;
} e[Ms];

void AddEdge(int u,int v,int w)
{
  e[++cnt]=(edge)
  {
    v,w,p[u]
  };
  p[u]=cnt;
}

int Min(int a,int b)
{
  if (!a)
    return b;
  else
    return a<b? a:b;
}

void Work()
{
  int u,v,w;
  while(~scanf("%d%d",&N,&M))
  {
    memset(im,0,sizeof(im));
    memset(p,0,sizeof(p));
    cnt=0;
    memset(vmin,0,sizeof(vmin));
    memset(e,0,sizeof(e));

    for (int i=0; i<M; ++i)
    {
      scanf("%d%d%d",&u,&v,&w);
      AddEdge(u+1,v+1,w);
      ++im[v+1];
    }

    queue<int> q;
    for (int i=1; i<=N; ++i)
      if (!im[i])
        q.push(i);
    while(!q.empty())
    {
      u=q.front();
      q.pop();
      for (int i=p[u]; i; i=e[i].next)
      {
        if (!vmin[e[i].v])
          vmin[e[i].v]=e[i].w+vmin[u];
        else
          vmin[e[i].v]=max(vmin[e[i].v],e[i].w+vmin[u]);
        --im[e[i].v];
        if (!im[e[i].v])
          q.push(e[i].v);
      }
    }
    int ans=0;
    for (int i=1; i<=N; ++i)
      ans=max(ans,vmin[i]);
    printf("%d\n",ans+1);
  }
}

int main()
{
  //freopen("project.in","r",stdin);
  //freopen("project.out","w",stdout);
  Work();
  return 0;
}

