#include <bits/stdc++.h>
using namespace std;

const int maxl = 200 + 10;
const int maxn = 1e3 + 10;

int l, n;
int c[maxl][maxl], ask[maxn];
int dp[2][maxl][maxl];

int main(void)
{
  //freopen("service.in", "r", stdin);
  //freopen("service.out", "w", stdout);
  scanf("%d%d", &l, &n);
  for (int i = 1; i <= l; i++)
    for (int j = 1; j <= l; j++)
      scanf("%d", &c[i][j]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &ask[i]);
  memset(dp, 0x7f, sizeof dp);
  dp[1][1][2] = dp[1][2][1] = c[3][ask[1]];//初始化状态
  dp[1][1][3] = dp[1][3][1] = c[2][ask[1]];
  dp[1][2][3] = dp[1][3][2] = c[1][ask[1]];
  for (int i = 2; i <= n; i++)
  {
    memset(dp[i&1], 0x7f, sizeof dp[i&1]); //务必清空，否则可能因为前面的值而造成影响
    for (int j=1; j<=l; j++)
      if (j!=ask[i-1]) //检查限制，下同
        for (int k=1; k<=l; k++)
          if (k!=j && k!=ask[i-1])
          {
            dp[i&1][j][k]=dp[i&1][k][j]=min(dp[i&1][j][k], dp[(i-1)&1][j][k]+c[ask[i-1]][ask[i]]);
            dp[i&1][j][ask[i-1]]=dp[i&1][ask[i-1]][j]=min(dp[i&1][j][ask[i-1]],dp[(i-1)&1][j][k]+c[k][ask[i]]);
            dp[i&1][k][ask[i-1]]=dp[i&1][ask[i-1]][k]=min(dp[i&1][k][ask[i-1]],dp[(i-1)&1][j][k]+c[j][ask[i]]);
          }
  }
  int ans = 0x7fffffff;
  for (int i = 1; i <= l; i++)
    if (i != ask[n])
      for (int j = 1; j <= l; j++)
        if (i != j && j != ask[n])
          ans = min(ans, dp[n & 1][i][j]);
  printf("%d\n", ans);
  return 0;
}

