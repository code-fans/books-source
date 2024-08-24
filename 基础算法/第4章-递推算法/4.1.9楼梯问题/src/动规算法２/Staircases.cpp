//楼梯问题 - 动规算法2
#include <bits/stdc++.h>
using namespace std;

long long f[505][505];

int main()
{
  freopen("Staircases.in","r",stdin);
  freopen("Staircases.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<=n; ++i)
    f[0][i]=1;
  for(int i=1; i<n; ++i)
  {
    for(int j=i; j<=n; ++j)
      f[j][i]=f[j-i][i-1]+f[j][i-1];
    for(int j=1; j<i; ++j)
      f[j][i]=f[j][i-1];
  }
  printf("%lld\n",f[n][n-1]);
  return 0;
}

