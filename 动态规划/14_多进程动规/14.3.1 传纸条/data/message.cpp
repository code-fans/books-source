//传纸条
#include<bits/stdc++.h>
using namespace std;
#define maxn 55

int f[maxn][maxn][maxn][maxn],a[maxn][maxn];

int Max(int a, int b, int c, int d)//返回4个值的最大值
{
  return max(a,max(b,max(c,d)));
}

int main()
{
  //freopen("message.in","r",stdin);
  //freopen("message.out","w",stdout);
  int n,m;
  cin >> n >> m;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      cin >> a[i][j];
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      for (int k=1; k<=n; k++)
        for (int l=j+1; l<=m; l++)//只要这里和j错开就可以避免重复走过同一点了
          f[i][j][k][l]=Max(f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1],f[i-1][j][k-1][l])+a[i][j]+a[k][l];
  cout << f[n][m-1][n-1][m] << endl;
  return 0;
}
