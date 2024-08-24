//数字分组1 - DP
//问题等价于从n个物品中选取若干个，其重量不超过总重量/2，且重量达到最大。
//以所有的石子的重量和为背包容量进行01背包，最后求两堆的最小差。
#include <bits/stdc++.h>
using namespace std;

int a[22];
int dp[2500000];

int main()
{
  freopen("Stone1.in","r",stdin);
  freopen("Stone1.out","w",stdout);
  int n;
  scanf("%d",&n);
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
    sum += a[i];
  }
  for(int i=0; i<n; i++)
    for(int k=sum; k>=a[i]; k--)
      dp[k] = max( dp[k],dp[k-a[i]] + a[i]);
  int mmin = INT_MAX;
  for(int i=0; i<=sum; i++)
    if( dp[i] && abs(sum-dp[i]-dp[i]) < mmin )
      mmin = abs(sum-dp[i]-dp[i]);
  printf("%d\n",mmin);
  return 0;
}


