//设dp[i][j]为假设第一个石头在压力i下测试，j个石头判断出压力值的最少次数。
//如果第一个石头在压力i下测试，如果碎了，那么则需要在1~i-1压力值中继续寻找，
//所需要的次数为dp[i-1][j-1]；没碎的话，需要在i+1~n中继续寻找，所需要的次数为dp[n-i][j]。
//所以就得到了递推方程dp[i][j] = dp[i-1][j-1] + dp[n-i][j]。
//
//初始状态为
//n == 0 || m == 0时，次数为0
//n == 1时，次数1，有n个压力最多n次，所以初始化为dp[i][]初始化为i
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N];

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  int n,m;
  while(~scanf("%d%d",&n,&m))
  {
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= m; j++)
        dp[i][j] = i;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= i; j++)
        for(int k = 2; k <= m; k++)
          dp[i][k] = min(dp[i][k],max(dp[j-1][k-1],dp[i-j][k])+1);
    printf("%d\n",dp[n][m]);
  }
  return 0;
}
