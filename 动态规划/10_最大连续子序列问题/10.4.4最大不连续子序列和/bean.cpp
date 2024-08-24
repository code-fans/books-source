//最大不连续子序列和
//在同一行里面，相邻的数字不能同时取，那么每一行都有会有一个最大值，
//那么可以把每一行最大值看成一个数字，再求一次，相当于在一行里面求
//最大不连续子序列的和，只是这里的每一个数字是每一行的最大值。
//dp[i]=max(dp[i-2]+a[i],dp[i-1])
//dp[i]代表到i时的最大子序列的和，对于每一个数字，只有取或者不取两种
//状态，如果取，那么最大值是从dp[i-2]再加上本身的数值，如果不取，那么
//最大值是dp[i-1]
#include <bits/stdc++.h>
using namespace std;

int a[200005],dp[200005];

int main()
{
  //freopen("bean.in","r",stdin);
  //freopen("bean.out","w",stdout);
  int n,m;
  while(scanf("%d %d",&n,&m)==2)
  {
    for(int i=1; i<=n; i++)            //先按行DP,求出每行能取到的最大值
    {
      for(int j=1; j<=m; j++)
        scanf("%d",&a[j]);
      for(int j=2; j<=m; j++)
        a[j]=max(a[j-1],a[j-2]+a[j]);
      dp[i]=a[m];                      //第i行能取到的最大值
    }
    for(int i=2; i<=n; i++)            //再按列dp,原理类似
      dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
    printf("%d\n",dp[n]);
  }
  return 0;
}
