//因为出现了环，对于动态规划有了后效性
#include<bits/stdc++.h>
using namespace std;

int a[1000][1000],dp[1000][1000];//d[i][j]表示从（i，j）这个位置到达底层的最短距离

int main()
{
  //freopen("tower.in","r",stdin);
  //freopen("tower.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    for(int j=0; j<=i; j++)
    {
      scanf("%d",&a[i][j]);
      dp[i][j]=1e9;
    }
  for(int i=0; i<n; i++)
  {
    dp[n-1][i]=a[n-1][i];
    dp[n-1][i]=dp[n-1][i-1]+a[n-1][i];  //因为最后一行右边的点只能从左边的推来，所以预处理
  }
  for(int i=n-1; i>=0; i--)
    dp[n-1][i]=min(dp[n-1][i],dp[n-1][(i+1)%n]+a[n-1][i]); //往左走的话，肯定要先从左边翻过去再向左走

  for(int i=n-2; i>=0; i--)                   //从底往上走
  {
    dp[i][0]=min(dp[i+1][0],dp[i+1][1]);     //对左边界的处理
    dp[i][0]=min(dp[i][0],dp[i+1][i+1]);
    dp[i][0]+=a[i][0];

    dp[i][i]=min(dp[i+1][0],dp[i+1][i]);    //对右边界的处理
    dp[i][i]=min(dp[i][i],dp[i+1][i+1]);
    dp[i][i]+=a[i][i];

    for(int j=1; j<=i-1; j++)                  //对中间位置的处理，这时候下面的一行已经处理完了
      dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+a[i][j];

    dp[i][0]=min(dp[i][0],dp[i][i]+a[i][0]);    //左推与右推
    for(int j=1; j<=i; j++)
      dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
    for(int j=i; j>=0; j--)
      dp[i][j]=min(dp[i][j],dp[i][(j+1)%(i+1)]+a[i][j]);
  }
  printf("%d\n",dp[0][0]);
  return 0;
}
