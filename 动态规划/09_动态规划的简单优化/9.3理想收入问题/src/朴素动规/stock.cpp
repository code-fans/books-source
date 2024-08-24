//理想收入问题 - 朴素动规
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("stock.in","r",stdin);
  freopen("stock.out","w",stdout);
  int n;
  scanf("%d",&n);
  double v[n+1],f[n+1];                   //动态开辟数组
  for(int i=1; i<=n; i++)
    scanf("%lf",&v[i]),f[i]=0;
  f[0]=1;
  for(int i=1; i<=n; i++)
    for(int j=0; j<i; j++)
      for(int k=j+1; k<=i; k++)
        f[i]=max(f[i],f[j]/v[k]*v[i]);
  printf("%.4lf\n",f[n]);
  return 0;
}

