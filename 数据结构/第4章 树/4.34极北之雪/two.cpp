//¼«±±Ö®Ñ©
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1e5+100;
struct Edge
{
  int v,w;
  int next;
} es[N<<1];
int head[N];
int n,s;
bool vis[N];
int step[N];
int sum;
int bfs(int &st)
{
  int maxn=-1;
  step[st]=0;
  memset(vis,0,sizeof(vis));
  queue<int> que;
  if(!que.empty()) que.pop();
  que.push(st);
  vis[st]=true;
  while(!que.empty())
  {
    int cur=que.front();
    que.pop();
    for(int i=head[cur]; ~i; i=es[i].next)
    {
      int v=es[i].v;
      if(!vis[v])
      {
        que.push(v);
        step[v]=step[cur]+es[i].w;
        if(step[v]>maxn)
        {
          maxn=step[v];
          st=v;
        }
        vis[v]=true;
      }
    }
  }
  return maxn;
}
void ini()
{
  memset(head,-1,sizeof(head));
  sum=0;
}
int main()
{
  freopen("two.in","r",stdin);
  freopen("two.out","w",stdout);
  while(~scanf("%d%d",&n,&s))
  {
    ini();
    for(int i=1; i<n; i++)
    {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      sum+=w;
      es[i].v=v,es[i].w=w,es[i].next=head[u];
      head[u]=i;
      es[i+n].v=u,es[i+n].w=w,es[i+n].next=head[v];
      head[v]=i+n;
    }
    bfs(s);
    printf("%d\n",2*sum-bfs(s));
  }
  return 0;
}
