//≤º’Û - ∑Ω∑®2
#include <bits/stdc++.h>
using namespace std;

unsigned long long f[35]= {1,1};

int main()
{
  //freopen("embattle.in","r",stdin);
  //freopen("embattle.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=2; i<=n+1; i++)
  {
    f[i]=f[i-1];
    for(int j=1; j<=i; j++)
      f[i]+=2*f[i-j-1];
  }
  printf("%llu\n",f[n+1]);
  return 0;
}

