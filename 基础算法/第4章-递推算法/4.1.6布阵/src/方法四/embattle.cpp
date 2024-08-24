//布阵 - 方法4
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("embattle.in","r",stdin);
  //freopen("embattle.out","w",stdout);
  long long n,f[2]= {1,3};                  //采用滚动数组
  scanf("%lld",&n);
  for(int i=2; i<=n; i++)
    f[i%2]=2*f[(i-1)%2]+f[(i-2)%2];
  printf("%lld\n",f[n%2]);
  return 0;
}

