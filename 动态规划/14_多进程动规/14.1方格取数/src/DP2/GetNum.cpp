//方格取数—DP2
#include <bits/stdc++.h>
using namespace std;

int val[15][15],dp[15][15][15][15];

int Max(int a,int b,int c,int d)
{
  return max(a,max(b,max(c,d)));
}

int main()
{
  freopen("GetNum.in","r",stdin);
  freopen("GetNum.out","w",stdout);
  int n,x,y,c;
  cin>>n;
  while(cin>>x>>y>>c, x && y && c)
    val[x][y]=c;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        for(int l=1; l<=n; l++)
          dp[i][j][k][l]=Max(dp[i-1][j][k-1][l],    //同时从上方过来
                             dp[i-1][j][k][l-1],    //分别从上方和左方过来
                             dp[i][j-1][k-1][l],    //分别从左方和上方过来
                             dp[i][j-1][k][l-1])    //同时从左方过来
                         +val[i][j]+(i==k&&j==l ? 0:val[k][l]);
  cout<<dp[n][n][n][n]<<endl;
  return 0;
}
