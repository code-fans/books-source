//求最大子序列和 - 方法4
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,sum=-2147483647,b=0,a[35000]= {0};
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  for(int i=n; i>=1; --i)
  {
    b+=a[i];
    if(b>sum)
      sum=b;
    if(b<0)
      b=0;
  }
  printf("%d\n",sum);
  return 0;
}

