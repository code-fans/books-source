//≤…“©-∆’Õ®–¥∑®
#include <bits/stdc++.h>
using namespace std;

int t,m,a[10001],b[10001],f[10001][10001];

int main()
{
  freopen("medic.in","r",stdin);
  freopen("medic.out","w",stdout);
  scanf("%d%d",&t,&m);
  for (int i=1; i<=m; i++)
    scanf("%d%d",&a[i],&b[i]);
  for (int i=1; i<=m; i++)
    for (int j=0; j<=t; j++)
    {
      f[i][j]=f[i-1][j];
      if ((j>=a[i])&&(f[i][j]<f[i-1][j-a[i]]+b[i]))
        f[i][j]=f[i-1][j-a[i]]+b[i];
    }
  printf("%d\n",f[m][t]);
  return 0;
}
