//动态规划01背包
#include<bits/stdc++.h>
using namespace std;
int dp[10001],n,ans;

struct goods
{
  int p,d;
  bool operator <(const goods x)const
  {
    return d<x.d;
  }
} a[10001];

int main()
{
  //freopen("supermarket.in","r",stdin);
  //freopen("supermarket.out","w",stdout);
  while (cin>>n)
  {
    memset(dp,0,sizeof(dp));
    for (int i=1; i<=n; i++)
      cin>>a[i].p>>a[i].d;
    sort(a+1,a+n+1);
    ans=0;
    for (int i=1; i<=n; i++)
      for (int j=a[i].d; j; j--)
      {
        dp[j]=max(dp[j],dp[j-1]+a[i].p);
        ans=max(ans,dp[j]);
      }
    printf("%d\n",ans);
  }
  return 0;
}
