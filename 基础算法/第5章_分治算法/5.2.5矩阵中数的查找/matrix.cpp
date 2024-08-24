//矩阵中数的查找
#include <bits/stdc++.h>
using namespace std;

long long const INF=0x3f3f3f3f3f3f3f;
long long N;

long long Cal(long long i,long long j)
{
  return i*i+100000*i+j*j-100000*j+i*j;
}

long long Judge(long long Mid)
{
  long long mid,ans=0,sum=0;
  for(int j=1; j<=N; j++)
  {
    for(int l=1,r=N; l<=r;)
    {
      mid=(l+r)>>1;
      if(Cal(mid,j)<=Mid)
      {
        ans=mid;
        l=mid+1;
      }
      else
        r=mid-1;
    }
    sum+=ans;
  }
  return sum;
}

int main()
{
  //freopen("matrix.in","r",stdin);
  //freopen("matrix.out","w",stdout);
  long long T,M,mid,ans;
  for(scanf("%lld",&T); T; T--)
  {
    scanf("%lld%lld",&N,&M);
    for(long long l=-1*INF,r=INF; l<=r;)
    {
      mid=(l+r)>>1;
      if(Judge(mid)>=M)
      {
        ans=mid;
        r=mid-1;
      }
      else
        l=mid+1;
    }
    printf("%lld\n",ans);
  }
  return 0;
}

