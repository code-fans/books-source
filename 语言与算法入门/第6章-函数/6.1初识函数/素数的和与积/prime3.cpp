//素数的和与积
#include <bits/stdc++.h>
using namespace std;

inline int pd(int x)
{
  for(int i=2; i*i<=x; i++)
    if(x%i==0)
      return 0;
  return 1;
}

int main()
{
  freopen("prime3.in","r",stdin);
  freopen("prime3.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=n/2; i>=2; i--)
    if(pd(i) && pd(n-i))
    {
      printf("%d\n",i*(n-i));
      return 0;
    }
  return 0;
}
