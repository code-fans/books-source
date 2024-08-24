//求最大子序列和 - 方法1
#include <bits/stdc++.h>
using namespace std;
#define MAX 35005

int main()
{
  int n,maxn,sum,a[MAX]= {0};
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  maxn=a[1];
  for(int i=1; i<=n; i++)
    for(int j=i; j<=n; j++)
    {
      sum=0;
      for(int k=i; k<=j; k++)
        sum+=a[k];
      if(sum>maxn)
        maxn=sum;
    }
  printf("%d\n",maxn);
  return 0;
}

