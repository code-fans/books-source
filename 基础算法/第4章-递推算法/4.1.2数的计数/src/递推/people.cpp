//数的计数 - 递推
#include <bits/stdc++.h>
using namespace std;

long long f[1005];

int main()
{
  freopen("people.in","r",stdin);
  freopen("people.out","w",stdout);
  int n;
  scanf("%d",&n);
  f[1]=1;
  for(int i=2; i<=n; i++)
  {
    f[i]=f[i-1];
    if((i&1)==0)
      f[i]=f[i]+f[i/2];
  }
  printf("%lld\n",f[n]);
  return 0;
}

