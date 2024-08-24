//楼梯问题 - 动规算法5
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("Staircases.in","r",stdin);
  //freopen("Staircases.out","w",stdout);
  int n;
  scanf("%d",&n);
  long long f[1005]= {1};
  for(int i=1; i<n; ++i)
    for(int j=n; j>=i; --j)
      f[j]+=f[j-i];
  printf("%lld\n",f[n]);
  return 0;
}

