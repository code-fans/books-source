//双人游戏 —动规算法一
#include <bits/stdc++.h>
using namespace std;

int n,num[101],dp[101][101],sum[101][101];

int main()
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  cin>>n;
  for (int i=1; i<=n; i++)
    cin>>num[i];
  for (int i=1; i<=n; i++)
  {
    sum[i][i]=num[i];
    for (int j=i+1; j<=n; j++)
      sum[i][j]=sum[i][j-1]+num[j];
  }
  for (int i=1; i<=n; i++)
    dp[i][i]=num[i];
  for (int l=1; l<n; l++)
    for (int i=1; i<=n-l; i++)
      dp[i][i+l]=sum[i][i+l]-min(dp[i][i+l-1],dp[i+1][i+l]);
  cout<<dp[1][n]<<" "<<sum[1][n]-dp[1][n]<<endl;
  return 0;
}

