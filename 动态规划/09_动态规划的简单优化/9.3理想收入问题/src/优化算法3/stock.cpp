//理想收入问题 - 优化算法3
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("stock.in","r",stdin);
  //freopen("stock.out","w",stdout);
  int n;
  scanf("%d",&n);
  double v[n+1],f[n+1];
  for(int i=1; i<=n; i++)
    scanf("%lf",&v[i]);
  f[0]=1;
  for(int i=1; i<=n; i++)
  {
    f[i]=f[i-1];
    for(int j=0; j<i; j++)
      if(f[j]/v[j+1]*v[i] > f[i])
        f[i]=f[j]/v[j+1]*v[i];
  }
  printf("%.4lf\n",f[n]);
  return 0;
}

