//网络巡视—DP
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<algorithm>
#define N 1555
using namespace std;
int money[N];
int son[N][N];
int dp[N][4];
void dfs(int x)
{
  if(!son[x][0])
  {
    dp[x][1] = money[x];
    dp[x][3] = money[x];
    dp[x][2] = 0;
    return ;
  }
  else
  {
    for(int i = 1; i<=son[x][0]; i++)
    {
      dfs(son[x][i]);
    }
    for(int i = 1; i<=son[x][0]; i++)
    {
      int s = son[x][i];
      dp[x][1] += min(dp[s][2],min(dp[s][3],dp[s][1]));//自己
      dp[x][2] += min(dp[s][1],dp[s][3]);//父亲
    }
    bool flag = 0;
    int bu = 2147438647;
    for(int i = 1; i<=son[x][0]; i++)
    {
      int s = son[x][i];
      dp[x][3] += min(dp[s][1],dp[s][3]);
      if(dp[s][3]>=dp[s][1])
      {
        flag = 1;
      }
      bu = min(bu,dp[s][1]-dp[s][3]);
    }
    if(flag==0)
    {
      dp[x][3]+=bu;
    }
  }
}
int main()
{
  //freopen("Net.in","r",stdin);
  //freopen("Net.out","w",stdout);
  int n;
  scanf("%d",&n);
  int root;
  for(int i = 1; i<=n; i++)
  {
    int num;
    scanf("%d",&num);
    if(i==1)
    {
      root = num;
    }
    scanf("%d",&money[num]);
    dp[num][1] = money[num];
    scanf("%d",&son[num][0]);
    for(int j = 1; j<=son[num][0]; j++)
    {
      scanf("%d",&son[num][j]);
    }
  }
  dfs(root);
  printf("%d\n",min(dp[root][1],dp[root][3]));
  return 0;
}

//以很明显这是树形DP。
//
//首先二维状态，dp[i][j]，j∈{1,2,3}
//
//dp[i][1]表示这个点被自己守卫。
//
//dp[i][2]表示这个点被父亲守卫。
//
//dp[i][3]表示这个点被儿子守卫。
//
//根据属性DP惯用套路，首先（DFS）搜索到叶节点，然后向上更新。
//
//如果这个点被自己守卫，那么他的儿子可能有三种状态，既可能是自己守卫，又可能被父亲守卫，还有可能被它的儿子守卫。
//
//用s来代表x的儿子，所以：
//
//dp[x][1] += min(dp[s][2],min(dp[s][3],dp[s][1]))；
//
//如果这个点被父亲守卫，那么他的儿子只可能被自己守卫，或者被它的儿子守卫。
//
//dp[x][2] += min(dp[s][1],dp[s][3]);
//
//那么最困难的是这个点被自己的儿子守卫，那么他的所有儿子同样是两种状态，
//被自己守卫或者被它的儿子守卫。且一定存在一个儿子被自己守卫。
//
//如果更新了一圈后，发现所有的儿子自己守卫的代价都要大于它们的儿子守卫
//它们的价值（即x的儿子s守卫的价值大于s的儿子守卫的价值），
//我们需要加上一个s自己守卫和s的儿子守卫的差量，并且保证这个差量最小。
//
//注意把所有点自己守卫自己的情况先赋上值。
