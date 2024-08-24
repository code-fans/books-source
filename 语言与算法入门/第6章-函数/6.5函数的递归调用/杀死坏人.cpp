//…±À¿ªµ»À
#include <bits/stdc++.h>
using namespace std;

int jo(int m,int k)
{
  int s=0,t=2*m;
  for(int i=1; i<=m; ++i)
  {
    s=(s-1+k)%t;
    --t;
    if(s<m)
      return 0;
  }
  return 1;
}

int main()
{
  int m,i,k;
  scanf("%d",&m);
  k=m+1;
  while(!jo(m,k))
    ++k;
  printf("%d\n",k);
  return 0;
}

