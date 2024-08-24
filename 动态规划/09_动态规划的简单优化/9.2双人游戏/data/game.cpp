//双人游戏 —动规算法二
#include<bits/stdc++.h>
using namespace std;

int dp[5001],sum[5001];

int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>dp[i];                       //相当于dp[i][i]
    sum[i]=sum[i-1]+dp[i];                    //前缀和
  }
  for(int l=2; l<=n; l++)                     //宽度逐渐增大
    for(int i=1; i<=n-l+1; i++)
      dp[i]=sum[i+l-1]-sum[i-1]-min(dp[i+1],dp[i]);
  cout<<dp[1]<<' '<<sum[n]-dp[1]<<endl;
  return 0;
}
