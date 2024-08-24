//购物问题
#include <bits/stdc++.h>
#define INF 1E100
using namespace std;

int ID1[110],ID2[1100];
double price[1100],dp[1100][1100];

int main()
{
  freopen("shopping.in","r",stdin);
  freopen("shopping.out","w",stdout);
  int n,m;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
  {
    cin>>ID1[i];
    dp[0][i]=INF;                  //初始化
  }
  for(int i=1; i<=m; i++)
    cin>>ID2[i]>>price[i];
  for(int i=1; i<=m; i++)           //枚举物品
    for(int j=0; j<=n; j++)         //枚举清章
    {
      dp[i][j]=dp[i-1][j];
      if(j>0 && ID1[j]==ID2[i] && dp[i-1][j-1]+price[i]<dp[i][j])
        dp[i][j]=dp[i-1][j-1]+price[i];
    }
  dp[m][n]>1E99?printf("Impossible\n"):printf("%0.2lf\n",dp[m][n]);
  return 0;
}

