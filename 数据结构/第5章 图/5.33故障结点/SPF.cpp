//故障结点
#include <bits/stdc++.h>
using namespace std;

vector<int>Map[1010];
int dfn[1010],low[1010],sub[1010];           //sub[]保存分割的块
int Index,Root,RootChild;

void tarjan(int u,int fa)
{
  dfn[u]=low[u]=++Index;
  for(int i=0; i<Map[u].size(); i++)
  {
    int v=Map[u][i];
    if(dfn[v]==-1)
    {
      tarjan(v,u);
      low[u]=min(low[u],low[v]);
      if(u==Root)
        RootChild++;
      else if(low[v]>=dfn[u])
        sub[u]++;                            //分割块数加一
    }
    else if(v!=fa)                           //注意不要忘了判断，保证不会回头走
      low[u]=min(low[u],dfn[v]);
  }
}

int main()
{
  freopen("SPF.in","r",stdin);
  freopen("SPF.out","w",stdout);
  int Case=0;
  while(1)
  {
    Index=0,RootChild=0;
    memset(Map,0,sizeof(Map));
    memset(dfn,-1,sizeof(dfn));
    memset(sub,0,sizeof(sub));
    int a,b,flag=0;
    while(1)
    {
      cin>>a;
      if(a)
      {
        cin>>b;
        flag=1;
        Map[a].push_back(b);
        Map[b].push_back(a);
      }
      else break;
    }
    if(!flag) break;                                //退出输入
    cout<<"Network #"<<++Case<<endl;
    Root=b;
    tarjan(Root,-1);
    flag=0;
    if(RootChild)
      sub[Root]=RootChild-1;
    for(int i=0; i<1005; i++)
      if(sub[i])
      {
        flag=1;
        cout<<"  SPF node "<<i<<" leaves "<<sub[i]+1<<" subnets"<<endl;
      }
    if(flag==0)
      cout<<"  No SPF nodes"<<endl;
    cout<<endl;
  }
  return 0;
}

