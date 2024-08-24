//ÂÃĞĞ-tarjanËã·¨ÕÒ»·
#include <bits/stdc++.h>
using namespace std;
#define M 5010
vector<int> v[M];
int n,m,num,sum,cnt,top;
int low[M],dfn[M],circle[M],ans[M],an[M],Stack[M];
bool vis[M],ok;

int DFS(int w,int fa)
{
  an[++num]=w;
  for(int i=0; i<v[w].size(); i++)
    if(!(v[w][i]==fa ||v[w][i]==0 ))
      DFS(v[w][i],w);
}

int tarjan(int u,int father)
{
  if(ok)return 0;
  low[u]=dfn[u]=++cnt;
  Stack[++top]=u;
  vis[u]=true;
  for(int i=0; i<v[u].size(); i++)
  {
    if(v[u][i]==father || v[u][i]==0)continue;
    if(!dfn[v[u][i]])
    {
      tarjan(v[u][i],u);
      low[u]=min(low[u],low[v[u][i]]);
    }
    else low[u]=min(low[u],dfn[v[u][i]]);
    if(ok)return 0;
  }
  if(dfn[u]==low[u])
  {
    int j;
    sum=0;
    do
    {
      j=Stack[top--];
      vis[j]=0;
      circle[++sum]=j;
    }
    while(j!=u);
    if(sum>1)ok=true;
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++)
  {
    int s1,s2;
    scanf("%d%d",&s1,&s2);
    v[s1].push_back(s2);
    v[s2].push_back(s1);
  }
  for(int i=1; i<=n; i++)
    sort(v[i].begin(),v[i].end());
  if(m!=n)
  {
    DFS(1,0);
    for(int i=1; i<=n; i++)
      printf("%d%c",an[i],i==n?'\n':' ');
  }
  else
  {
    memset(ans,127,sizeof(ans));
    ok=false;
    tarjan(1,0);//Ñ°ÕÒ»·
    for(int i=1; i<=sum; i++)
    {
      num=0;
      int w1,w2,a=circle[i],b=circle[i%sum+1];
      for(int j=0; j<v[a].size(); j++)
        if(v[a][j]==b)
        {
          w1=j;
          v[a][j]=0;//É¾±ß
          break;
        }
      for(int j=0; j<v[b].size(); j++)
        if(v[b][j]==a)
        {
          w2=j;
          v[b][j]=0;//É¾±ß
          break;
        }
      DFS(1,0);//±éÀú
      v[a][w1]=b;//»Ö¸´É¾³ıµÄ±ß
      v[b][w2]=a;//»Ö¸´É¾³ıµÄ±ß
      for(int j=1; j<=n; j++)
      {
        if(ans[j]<an[j])break;
        if(ans[j]>an[j])
        {
          for(int k=j; k<=n; k++)
            ans[k]=an[k];
          break;
        }
      }
    }
    for(int i=1; i<=n; i++)
      printf("%d%c",ans[i],i==n?'\n':' ');
  }
  return 0;
}
