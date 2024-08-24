//01±³°üÎÊÌâ
#include <bits/stdc++.h>
using namespace std;

int w[1001],c[1001],f[1001][1001];

int main()
{
  freopen("bag01.in","r",stdin);
  freopen("bag01.out","w",stdout);
  int m,n;
  scanf("%d%d",&m,&n);
  for(int i=1; i<=n; i++)
    scanf("%d%d",&w[i],&c[i]);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      if(j>=w[i])
        f[i][j]=max(f[i-1][j-w[i]]+c[i],f[i-1][j]);
      else
        f[i][j]=f[i-1][j];
  printf("%d\n",f[n][m]);
  return 0;
}
