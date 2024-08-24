//最长不下降序列 - 朴素算法
#include <bits/stdc++.h>
using namespace std;

int a[100001],dp[100001];

int main()
{
  freopen("LIS.in","r",stdin);
  freopen("LIS.out","w",stdout);
  int n,longest = 1;
  scanf("%d",&n);
  for (int i=1; i<=n; ++i)
  {
    scanf("%d",&a[i]);
    dp[i]=1;
  }
  for (int i=2; i<=n; ++i)
  {
    for (int j=1; j<i; j++)
      if(a[j]<=a[i] && dp[j]+1>dp[i])
        dp[i]=dp[j]+1;
    longest=max(dp[i],longest);
  }
  printf("%d\n",longest);
  return 0;
}

