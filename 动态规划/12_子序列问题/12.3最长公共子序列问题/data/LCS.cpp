//最长公共子序列问题 - 算法2
#include <bits/stdc++.h>
using namespace std;
#define M 501

char s1[M],s2[M];
int dp[M][M];
int n1,n2;

int main()
{
  //freopen("LCS.in","r",stdin);
  //freopen("LCS.out","w",stdout);
  cin>>n1;
  for(int i=1; i<=n1; ++i)
    cin>>s1[i];
  cin>>n2;
  for(int i=1; i<=n2; ++i)
    cin>>s2[i];
  for(int i=1; i<=n1; ++i)
    for(int j=1; j<=n2; ++j)
      if(s1[i]==s2[j])
        dp[i][j]=dp[i-1][j-1]+1;
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  cout<<dp[n1][n2]<<endl;
  return 0;
}

