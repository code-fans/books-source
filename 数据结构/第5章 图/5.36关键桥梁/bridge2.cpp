#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#define N 10001
using namespace std;
int head[N],num,dfs[N],low[N],n,m,idx,bridge[N],bum;
struct edge
{
  int st,ed,next;
} E[N*20];
void addedge(int x,int y)
{
  E[num].st=x;
  E[num].ed=y;
  E[num].next=head[x];
  head[x]=num++;
}
int cmp(const void *a,const void *b)
{
  return *(int *)a-*(int *)b;
}
void Tarjan(int u,int father)
{
  int i,v;
  low[u]=dfs[u]=idx++;
  for(i=head[u]; i!=-1; i=E[i].next)
  {
    v=E[i].ed;
    if(v==father)continue;
    if(dfs[v]==-1)
    {
      Tarjan(v,u);
      low[u]=low[u]>low[v]?low[v]:low[u];
      if(low[v]>dfs[u])//ге
      {
        bridge[bum++]=i;
      }
    }
    else low[u]=low[u]>dfs[v]?dfs[v]:low[u];
  }
}
int main()
{
  //freopen("bridge21.in","r",stdin);
  //freopen("bridge21.ans","w",stdout);
  int i,x,y,j,t,sum;
  char str[2][200];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    num=0;
    sum=1;
    map<string,int>mp;
    map<int,string>mmp;
    for(i=0; i<m; i++)
    {
      scanf("%s%s",str[0],str[1]);
      if(mp[str[0]]==0)
      {
        mp[str[0]]=sum;
        mmp[sum]=str[0];
        sum++;
      }
      if(mp[str[1]]==0)
      {
        mp[str[1]]=sum;
        mmp[sum]=str[1];
        sum++;
      }
      x=mp[str[0]];
      y=mp[str[1]];
      addedge(x,y);
      addedge(y,x);
    }
    memset(dfs,-1,sizeof(dfs));
    idx=0;
    bum=0;
    Tarjan(1,-1);
    for(i=1; i<=n; i++)
    {
      if(dfs[i]==-1)
        break;
    }
    if(i<=n)
    {
      printf("0\n");
      continue;
    }
    printf("%d\n",bum);
    qsort(bridge,bum,sizeof(bridge[0]),cmp);
    for(j=0; j<bum; j++)
    {
      i=bridge[j];
      i=(i/2*2);
      x=E[i].st;
      y=E[i].ed;
      if(x!=y)
        printf("%s %s\n",mmp[E[i].st].c_str(),mmp[E[i].ed].c_str());
    }
  }
  return 0;
}
