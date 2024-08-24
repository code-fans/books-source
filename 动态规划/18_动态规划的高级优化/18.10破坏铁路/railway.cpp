//破坏铁路——四边形不等式优化
//dp[i][k]表示在前i个铁路上放k个炸弹的最小值，cost[i][j]表示[i,j]区间内的价值
//dp[i][k]=min(dp[j][k-1]+cost[j+1][i]);
//cost[i][j]=cost[i][j-1]+sum*a[j],sum==(a[i]+a[i+1]+a[i+2]+,,,,+a[j-1])
#include <bits/stdc++.h>
using namespace std;
#define M 1100
#define LL long long
const LL INF =1e18;

int n,m;
int s[M][M];
LL a[M],cost[M][M],dp[M][M],sum[M];

int main()
{
  freopen("railway.in","r",stdin);
  freopen("railway.out","w",stdout);
  while(scanf("%d%d",&n,&m) && n)
  {
    for(int i=1; i<=n; i++)
    {
      scanf("%lld",&a[i]);
      sum[i]=sum[i-1]+a[i];
    }
    for(int i=1; i<=n; i++)
      for(int j=i+1; j<=n; j++)
        cost[i][j]=cost[i][j-1]+(sum[j-1]-sum[i-1])*a[j];//计算某段铁路的价值
    for(int i=0; i<=n; i++)
    {
      s[i][0]=0;                 //最优决策点的边界条件
      s[n+1][i]=n;               //边界条件
      dp[i][0]=cost[1][i];
    }
    for(int k=1; k<=m; k++)      //DP
      for(int i=n; i>=1; i--)
      {
        dp[i][k]=INF;
        for(int j=s[i][k-1]; j<=s[i+1][k]; j++)
          if((dp[j][k-1]+cost[j+1][i])<dp[i][k])
          {
            dp[i][k]= dp[j][k-1]+cost[j+1][i];
            s[i][k]=j;
          }
      }
    printf("%lld\n",dp[n][m]);
  }
  return 0;
}
