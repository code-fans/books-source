//序列的逆序数-暴力枚举
#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
  freopen("samsara.in","r",stdin);
  freopen("samsara.out","w",stdout);
  int n;
  while (scanf ("%d",&n)!=-1)
  {
    for (int i=0; i<n; i++)
      scanf ("%d",&a[i]);
    int sum=0;
    for (int i=0; i<n; i++)          //计算初始序列的逆序数
      for (int j=i+1; j<n; j++)
        if (a[i]>a[j])
          sum++;
    int minn=sum;
    for (int i=0; i<n; i++)
    {
      sum=sum-a[i]+(n-a[i]-1);
      minn=min(sum,minn);
    }
    cout<<minn<<endl;
  }
  return 0;
}

