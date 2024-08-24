//最大连续子序列和 - 动规算法
#include <bits/stdc++.h>
using namespace std;

int n,Max=-INT_MAX,a[100001];

int main()
{
  freopen("Csum.in","r",stdin);
  freopen("Csum.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  int sum=0;
  for (int i=1; i<=n; ++i)
  {
    sum+=a[i];
    if(sum>Max)
      Max=sum;
    if(sum<0)
      sum=0;
  }
  printf("%d\n",Max);
  return 0;
}

