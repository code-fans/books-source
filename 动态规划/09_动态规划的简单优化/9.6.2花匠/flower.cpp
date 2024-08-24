//花匠
#include<bits/stdc++.h>
using namespace std;

int h[100010],dp[100010][2];
int n;

int main()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&h[i]);
  dp[1][0]=dp[1][1]=1;
  for(int i=2; i<=n; i++)
  {
    h[i]>h[i-1]?dp[i][0]=dp[i-1][1]+1:dp[i][0]=dp[i-1][0];
    h[i]<h[i-1]?dp[i][1]=dp[i-1][0]+1:dp[i][1]=dp[i-1][1];
  }
  cout<<max(dp[n][0],dp[n][1])<<endl;
  return 0;
}
