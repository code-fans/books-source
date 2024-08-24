//理想收入问题 - 优化算法4
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("stock.in","r",stdin);
  freopen("stock.out","w",stdout);
  int n;
  scanf("%d",&n);
  double v[n+1],f[n+1],g[n+1];
  for(int i=1; i<=n; i++)
    scanf("%lf",&v[i]);
  f[0]=1;
  g[0]=0;
  for(int i=1; i<=n; i++)
  {
    g[i]=max(g[i-1],f[i-1]/v[i]);
    f[i]=max(f[i-1],g[i-1]*v[i]);
  }
  printf("%.4lf \n",f[n]);
  return 0;
}

