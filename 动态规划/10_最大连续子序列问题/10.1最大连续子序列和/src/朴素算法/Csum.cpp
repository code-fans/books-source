//最大连续子序列和 - 朴素算法
#include <bits/stdc++.h>
using namespace std;

int a[100001];

int main()
{
  freopen("Csum.in","r",stdin);
  freopen("Csum.out","w",stdout);
  int Max=-INT_MAX,n;
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  for(int i=1; i<=n; ++i)
  {
    int sum=0;
    for (int j=i; j<=n; ++j)
    {
      sum+=a[j];
      if(sum>Max)
        Max=sum;
    }
  }
  printf("%d\n",Max);
  return 0;
}

