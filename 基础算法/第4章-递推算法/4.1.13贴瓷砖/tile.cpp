//����ש
#include<bits/stdc++.h>
using namespace std;

int f[1000010],g[1000010];

int main()
{
  freopen("tile.in","r",stdin);
  freopen("tile.out","w",stdout);
  int n;
  scanf("%d",&n);
  f[0]=f[1]=g[1]=1;
  for(int i=2; i<=n; i++)
  {
    g[i]=(g[i-1]+f[i-1])%10000;
    f[i]=((f[i-1]+f[i-2])%10000+2*g[i-2]%10000)%10000;
  }
  printf("%d\n",f[n]);
  return 0;
}
