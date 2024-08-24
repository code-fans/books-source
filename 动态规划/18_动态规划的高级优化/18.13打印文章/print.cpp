#include <bits/stdc++.h>
using namespace std;
const int MAXN=510000;

long long a[MAXN],sum[MAXN],dp[MAXN],n,M;

long long Getup (long long j,long long k)//斜率计算分子部分
{
  return dp[j]+sum[j]*sum[j]-(dp[k]+sum[k]*sum[k]);
}

long long Getdown (long long j,long long k)//斜率计算分母部分
{
  return 2*(sum[j]-sum[k]);
}

int main()
{
  //freopen("print.in","r",stdin);
  //freopen("print.out","w",stdout);
  while (scanf("%lld %lld",&n,&M)==2)
  {
    for(int i=1; i<=n; i++)
      scanf("%lld",a+i);
    sum[0]=dp[0]=0;
    for(int i=1; i<=n; i++)
      sum[i]=sum[i-1]+a[i];
    int q[MAXN];
    int head=0,tail=0;
    q[tail++]=0;
    for(int i=1; i<=n; i++)
    {
      while (head+1<tail && Getup(q[head+1],q[head])<=sum[i]*Getdown(q[head+1],q[head]))
        head++;
      dp[i]=dp[q[head]]+M+(sum[i]-sum[q[head]])*(sum[i]-sum[q[head]]);
      while (head+1<tail && Getup(i,q[tail-1])*Getdown(q[tail-1],q[tail-2])<=Getup(q[tail-1],q[tail-2])*Getdown(i,q[tail-1]) )
        tail--;
      q[tail++]=i;
    }
    cout<<dp[n]<<endl;
  }
  return 0;
}
