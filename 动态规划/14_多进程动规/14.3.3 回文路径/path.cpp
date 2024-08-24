//回文路径
//首先想到f[i][j][k][l]表示从左上角走到(i,j)，从右下角走到(k,l)，
//在路径长度相等的情况下，所经过路径相同的方案数，然后动规方程显而易见。
//是这样做显然会爆时间，考虑降维，实际上只要枚举走过的步数和两个
//点所在的行数，就可以推出他们的位置，因此f[i][j][k]表示第一个点在第i行，
//第2个点在第j行，都走了k步的方案数。这样时间复杂度为O(n^3)，原题时限2s，
//高性能评测1s应该没问题。
//然后考虑空间，先写出三维状态的转移方程：
//f[i][j][k]=(f[i-1][j][k-1]+f[i][j][k-1]+f[i][j+1][k-1]+f[i-1][j+1][k-1])%mod;
//很显然步数之和上一层状态有关系，所以可以用滚动数组优化：
//f[i][j][now]=(f[i-1][j][pre]+f[i][j][pre]+f[i][j+1][pre]+f[i-1][j+1][pre])%mod;
#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int MOD=1000000007;

int n,f[2][N][N];
char s[N][N];

int main()
{
//  freopen("path.in","r",stdin);
//  freopen("path.out","w",stdout);

  scanf("%d",&n);
  for (int i=1; i<=n; i++) scanf("%s",s[i]+1);
  if (s[1][1]==s[n][n]) f[0][0][0]=1;
  int now=0;
  for (int i=1; i<n; i++)
  {
    now^=1;
    for (int j=0; j<=i; j++)
      for (int k=0; k<=i; k++)
        f[now][j][k]=0;
    for (int j=0; j<i; j++)
      for (int k=0; k<i; k++)
        if (f[now^1][j][k])
        {
          int x1=j+1,y1=i-j,x2=n-k,y2=n-i+1+k;
          if (s[x1+1][y1]==s[x2-1][y2]) (f[now][j+1][k+1]+=f[now^1][j][k])%=MOD;
          if (s[x1][y1+1]==s[x2-1][y2]) (f[now][j][k+1]+=f[now^1][j][k])%=MOD;
          if (s[x1+1][y1]==s[x2][y2-1]) (f[now][j+1][k]+=f[now^1][j][k])%=MOD;
          if (s[x1][y1+1]==s[x2][y2-1]) (f[now][j][k]+=f[now^1][j][k])%=MOD;
        }
  }
  int ans=0;
  for (int i=0; i<n; i++)
    (ans+=f[now][i][n-1-i])%=MOD;
  printf("%d\n",ans);
  return 0;
}
