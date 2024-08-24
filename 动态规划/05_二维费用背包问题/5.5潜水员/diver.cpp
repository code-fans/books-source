//潜水员
//和其它背包问题不同的是，携带的气体量可以超过所需的量 
#include<bits/stdc++.h>
using namespace std;

int dp[25][85], a[1005], b[1005], w[1005];

int main()
{
  freopen("diver.in","r",stdin);
  freopen("diver.out","w",stdout);
  int n, m, num;
  scanf("%d%d%d", &m, &n, &num);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < num; i++)
  {
    scanf("%d%d%d", &a[i], &b[i], &w[i]);
    for (int j = m; j >= 0; j--)         //氧气需要量 
      for (int k = n; k >= 0; k--)       //氮气需要量 
      {
        int t1 = min(m, j + a[i]);       //若超过需求，直接等于需求 
        int t2 = min(n, k + b[i]);
        dp[t1][t2] = min(dp[t1][t2], dp[j][k] + w[i]);
      }
  }
  printf("%d\n", dp[m][n]);
  return 0;
}
