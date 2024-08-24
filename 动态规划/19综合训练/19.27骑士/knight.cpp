#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll n, a[N], x, y, father[N], dp[N][2],sum,vist[N];
vector<int>son[N];
void dfs(int k,int x)
{
  //标记连通块上所有点
  vist[k] = 1;
  dp[k][1] = a[k];
  for (int i = 0; i < son[k].size(); i++)
  {
    int u = son[k][i];
    //环被拆开的位置
    if (x == u)continue;
    dfs(u,x);
    dp[k][1] += dp[u][0];
    dp[k][0] += max(dp[u][1], dp[u][0]);
    //使用后顺带清理数据
    dp[u][0] = 0;
    dp[u][1] = 0;
  }
}
//找环
void dfs0(int k)
{
  //给进过的点做记号
  vist[k] = 1;
  int u = father[k];
  //找到对应环
  if (vist[u])
  {
    //分别以u,k为根节点建树,连通块的最大战力为max(dp[u][0],dp[k][0])
    dfs(k, k);
    x = dp[k][0];
    dp[k][0] = 0;
    dp[k][1] = 0;
    dfs(u, u);
    y = dp[u][0];
    dp[u][0] = 0;
    dp[u][1] = 0;
    sum+=max(x,y);
  }
  else
    dfs0(u);
}
int main()
{
  freopen("knight.in","r",stdin);
  freopen("knight.out","w",stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i] >> y;
    father[i] = y;
    //靠逆向查找建树
    son[y].push_back(i);
  }
  for (int i = 1; i <= n; i++)
  {
    if(vist[i]==0)dfs0(i);
  }
  cout << sum << endl;
  return 0;
}

