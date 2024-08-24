//≈≈∂” - µ›Õ∆À„∑®
#include <bits/stdc++.h>
using namespace std;
int a[30002],f[30002],g[30002];

int main()
{
  freopen("queue.in","r",stdin);
  freopen("queue.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  f[1]=a[1]==1?0:1;
  g[n]=a[n]==2?0:1;
  for(int i=2; i<=n; ++i)
    f[i]=f[i-1]+(a[i]-1);
  for(int i=n-1; i>=1; --i)
    g[i]=g[i+1]+(a[i]%2);
  int Min=0x7fffffff;
  for(int i=0; i<=n; ++i)
    Min=min(f[i]+g[i+1],Min);
  printf("%d\n",Min);
  return 0;
}

