//最长滑雪道
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;
vector<pair<int,int>>G[MAXN];        //邻接表，1st存结点，2nd存边权
int inDegree[MAXN];                  //统计每个结点入度
int dp[MAXN];                        //从初始结点到第i个结点的最长路径和
int n,m;

void TopSort()
{
  queue<int>q;
  while(!q.empty())
    q.pop();                         //清空队列
  for(int i=1; i<=n; i++)            //扫描结点
    if(inDegree[i]==0)
      q.push(i);                     //把入度为0的结点扔进队列

  while(!q.empty())
  {
    int u=q.front();                 //取出队首结点
    q.pop();                         //删除该点
    for(int i=0; i<G[u].size(); i++) //遍历与点u相邻的边并删除
    {
      int v=G[u][i].first;
      inDegree[v]--;
      if(inDegree[v]==0)
        q.push(v);                   //入度为0的点存入队列
      dp[v]=max(dp[v],dp[u]+G[u][i].second);
    }
  }
}

int main()
{
  freopen("skiing.in","r",stdin);
  freopen("skiing.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    memset(inDegree,0,sizeof(inDegree));
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
      G[i].clear();
    scanf("%d %d",&n,&m);
    int u,v,w;
    for(int i=0; i<m; i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      G[u].push_back(make_pair(v,w));
      inDegree[v]++;
    }
    TopSort();
    int ans=-1;
    for(int i=1; i<=n; i++)
      ans=max(ans,dp[i]);
    printf("%d\n",ans);
  }
  return 0;
}

