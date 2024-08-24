//切割金属棍
//设最短的金属棍为l,最长的金属棍为r,二分不断尝试最佳切割长度满足k根
#include<bits/stdc++.h>
using namespace std;
int n,k;
double l,r,mid,a[100005];

inline bool Try(double x)
{
  int count=0;
  for(int i=1; i<=n; i++)
    count+=floor(a[i]/x);
  return count>=k;
}

int main()
{
  freopen("cut.in","r",stdin);
  freopen("cut.out","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=1; i<=n; i++)
  {
    scanf("%lf",&a[i]);
    l=l<a[i]?l:a[i];            //找出最短的金属棍
    r=r>a[i]?r:a[i];            //找出最长的金属棍
  }
  while(r-l>1e-6)
  {
    mid=(l+r)/2;                //浮点数无法用位运算
    Try(mid) ? l=mid:r=mid;
  }
  printf("%.2lf",floor(r*100)/100);//floor(x)返回的是小于或等于x的最大整数
  return 0;
}
