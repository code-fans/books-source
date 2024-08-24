//最大子序列和 - 方法2
#include <bits/stdc++.h>
using namespace std;
#define MAX 35005

int main()
{
  int n,maxn,s[MAX]= {0},a[MAX]= {0};
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
  }
  maxn=a[1];
  for(int i=1; i<=n; i++)
    for(int j=i; j<=n; j++)
      if(s[j]-s[i-1]>maxn)
        maxn=s[j]-s[i-1];
  printf("%d\n",maxn);
  return 0;
}

