//偶数3的个数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("number3.in","r",stdin);
  freopen("number3.out","w",stdout);
  int n;
  scanf("%d",&n);
  long long a[2]= {0,9},b[2]= {0,1};                //滚动数组
  for(int i=2; i<=n; i++)
  {
    a[i%2]=b[(i-1)%2]+9*a[(i-1)%2];
    b[i%2]=a[(i-1)%2]+9*b[(i-1)%2];
  }
  printf("%lld\n",a[n%2]-a[(n-1)%2]);
  return 0;
}

