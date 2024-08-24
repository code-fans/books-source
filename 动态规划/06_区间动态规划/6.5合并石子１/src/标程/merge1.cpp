//合并石子1
#include <bits/stdc++.h>
using namespace std;
#define MAXN 101

int a[MAXN],g[MAXN][MAXN],dp[MAXN][MAXN];

int main()
{
  //freopen("merge1.in","r",stdin);
  //freopen("merge1.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  for(int i=1; i<=n; i++)
    for(int j=i; j<=n; j++)
      g[i][j]=g[i][j-1]+a[j];
  for(int s=2; s<=n; s++)
    for(int i=1,j=s; j<=n; i++,j++)
    {
      dp[i][j]=1<<30;
      for(int k=i; k<j; k++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+g[i][j]);
    }
  printf("%d\n",dp[1][n]);
  return 0;
}

