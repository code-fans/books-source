/*
快乐假期
DP+单调队列.
处理一个前缀和sum.
要求ans=sum[i]-min{sum[k]}(i-Q<=k<=i-P)
要使ans最大,则sum[k]最小
单调队列维护单调递增区间保存sum的值，每次队首取出最小值
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define LL long long

LL n,ans=-1e18,head,tail,P,Q;
LL q[MAXN],sum[MAXN];

inline LL Read(LL x=0)                   //以字符串形式读入数字可提速
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //位运算优化即x*8+x*2=x*10
  return x;
}

int main()
{
  //freopen("happy.in","r",stdin);
  //freopen("happy.out","w",stdout);
  n=Read();
  P=Read();
  Q=Read();
  for(int i=1; i<=n; i++)
  {
    sum[i]=Read();
    sum[i]+=sum[i-1];            //前缀和
  }
  for(int i=P; i<=n; i++)        //从P开始
  {
    while(head<tail && sum[i-P]<sum[q[tail-1]])//单调队列 
      tail--;
    q[tail++]=i-P;               //插入队列,因为从p开始，所以-p 
    while(head<tail&&i-q[head]>Q)  //调整队列长度不超过Q 
      head++;
    ans=max(ans,sum[i]-sum[q[head]]);
  }
  printf("%lld\n",ans);
  return 0;
}
