//第k小数3  - 方法2
#include <bits/stdc++.h>
using namespace std;

long long a[109999],b[109999];
long long n,m;

long long Cal(long long MID)         //计算x在两数组中的排序数
{
  long long Mid,Min,Max,Cnt=0;
  for(int i=1; i<=n; i++)
  {
    Min=a[i]+b[1];                   //上界
    Max=a[i]+b[m];                   //下界
    if(MID<Min)                      //该轮中所有的两数和都比MID要大
      break;                         //则无累加，跳出该循环
    if(MID>=Max)                     //该轮中所有的两数和都比MID要小
    {
      Cnt+=m;                        //则累加m
      continue;
    }
    long long ll=1,rr=m;
    while(ll<=rr)                    //二分快速定位
    {
      Mid=(ll+rr)>>1;
      MID<a[i]+b[Mid]?rr=Mid-1:ll=Mid+1;
    }
    if(MID!=(a[i]+b[ll]))            //调整到正确的位置
      ll--;
    Cnt+=ll;
  }
  return Cnt;
}

long long FindKth(long long ll,long long rr,long long k)
{
  long long Mid;
  while(ll<=rr)
  {
    Mid=(ll+rr)>>1;
    k<=Cal(Mid)?rr=Mid-1:ll=Mid+1;
  }
  return ll;
}

int main()
{
  freopen("k3.in","r",stdin);
  freopen("k3.out","w",stdout);
  long long k;
  while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
  {
    for(int i=1; i<=n; i++)
      scanf("%lld",&a[i]);
    for(int i=1; i<=m; i++)
      scanf("%lld",&b[i]);
    printf("%lld\n",FindKth(a[1]+b[1],a[n]+b[m],k));
  }
  return 0;
}

