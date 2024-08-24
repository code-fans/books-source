//炸桥
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N = 1010;

struct node
{
  int v,man,id;
} n1,n2;
vector<node>Map[N];
int dfn[N],low[N];
int index,ans;

int Dfs(int u,int fa)                  //fa存储的是u的父亲边，而不是父结点
{
  low[u] = dfn[u] = ++index;
  for(int i=0; i<Map[u].size(); i++)
  {
    int v = Map[u][i].v;
    int id = Map[u][i].id;
    if(id == fa) continue;             //防止重边
    if(!dfn[v])
    {
      Dfs(v,id);                       //注意第2个参数是id
      low[u] = min(low[u],low[v]);
      if(low[v] > dfn[u])              //找到桥
        ans = min(ans,Map[u][i].man);  //更新最小的人数
    }
    else
      low[u] = min(low[u],dfn[v]);
  }
}

int main()
{
  freopen("bridge.in","r",stdin);
  freopen("bridge.out","w",stdout);
  int t,n,m;
  while(~scanf("%d%d",&n,&m) && n+m)
  {
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=0; i<=n; i++)
      Map[i].clear();
    index = 0;
    ans = INF;
    int a,b,c,cnt=0;                   //cnt统计联通分量个数
    for(int ID=1; ID<=m; ID++)
    {
      scanf("%d%d%d",&a,&b,&c);
      n1.v=b,n1.man=c,n1.id=ID;
      n2.v=a,n2.man=c,n2.id=ID;
      Map[a].push_back(n1);
      Map[b].push_back(n2);
    }
    for(int i=1; i<=n; i++)            //枚举，因为可能多于一个联通分量
      if(!dfn[i])
      {
        cnt++;
        Dfs(i,0);
      }
    if(cnt > 1)                        //图不联通就不用去了
      ans = 0;
    else if(ans == INF)
      ans = -1;
    else if(ans == 0)                  //没人看守,也要派一个去
      ans = 1;
    printf("%d\n",ans);
  }
  return 0;
}

