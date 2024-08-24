//楼梯问题 - 动规算法6
#include <bits/stdc++.h>
using namespace std;

long long g[501][501];

int main()
{
  freopen("Staircases.in","r",stdin);
  freopen("Staircases.out","w",stdout);
  int m;
  scanf("%d",&m);
  for(int i=1; i<=m; ++i)
    g[i-1][0]=1;
  for(int i=1; i<m; ++i)
    for(int j=1; j<=m; ++j)
      if(j>=i)
        g[i][j]=g[i-1][j]+g[i-1][j-i];
      else g[i][j]=g[i-1][j];
  printf("%lld\n",g[m-1][m]);
  return 0;
}

