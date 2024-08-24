//储钱罐-完全背包求最小值
#include <bits/stdc++.h>
using namespace std;

int dp[10002], w[502], v[502];

int main()
{
  freopen("Piggy.in","r",stdin);
  freopen("Piggy.out","w",stdout);
  int T,E,F,N,W;
  for(cin>>T; T; T--)
  {
    cin>>E>>F>>N;
    W=F-E;
    for (int i=0; i<N; i++)
      cin>>v[i]>>w[i];
    dp[0] = 0;
    for (int i=1; i<=W; i++)
      dp[i]=1E9;
    for (int i=0; i<N; i++)                 //枚举物品即硬币
      for (int j=w[i]; j<=W; j++)           //枚举罐的容量
        dp[j]=min(dp[j], dp[j-w[i]]+v[i]);  //完全背包，求最小值
    if (dp[W]<1E9)
      cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<".\n";
    else
      cout<<"This is impossible.\n";
  }
  return 0;
}
