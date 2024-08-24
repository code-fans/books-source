//信息传递
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;

stack<int>st;
vector<int>vec[MAXN];
int n,cnt,idx,ans=MAXN;
int dfn[MAXN],low[MAXN],vis[MAXN];

void Tarjan(int x)
{
  low[x]=dfn[x]=++idx;
  st.push(x);
  vis[x]=1;
  for(int i=0; i<vec[x].size(); i++)
  {
    int v=vec[x][i];
    if(!dfn[v])
    {
      Tarjan(v);
      low[x]=min(low[x],low[v]);
    }
    else if(vis[v])
      low[x]=min(low[x],dfn[v]);
  }
  if(low[x]==dfn[x])                 //找到环
  {
    vis[x]=0;
    for(cnt=1; st.top()!=x; cnt++)   //cnt统计环中结点个数,初始为1
      st.pop();                      //因为st.top=x时循环结束,cnt少算一个
    if(cnt>2)                        //一个结点不是环
      ans=min(ans,cnt);
  }
}

int main()
{
  freopen("message.in","r",stdin);
  freopen("message.out","w",stdout);
  scanf("%d",&n);
  for(int i=1,x; i<=n; i++)
  {
    scanf("%d",&x);
    vec[i].push_back(x);
  }
  for(int i=1; i<=n; i++)
    if(!dfn[i])
      Tarjan(i);
  printf("%d\n",ans);
  return 0;
}

