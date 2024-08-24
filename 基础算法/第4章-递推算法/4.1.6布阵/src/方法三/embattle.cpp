//≤º’Û - ∑Ω∑®3
#include <bits/stdc++.h>
using namespace std;

long long f1[35]= {1},f2[35]= {1};

int main()
{
  freopen("embattle.in","r",stdin);
  freopen("embattle.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n+1; i++)
  {
    f1[i]=f1[i-1]+2*f2[i-1];
    f2[i]=f1[i-1]+f2[i-1];
  }
  printf("%lld\n",f1[n]);
  return 0;
}

