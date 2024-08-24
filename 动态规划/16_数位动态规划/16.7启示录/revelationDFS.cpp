//启示录
#include <bits/stdc++.h>
using namespace std;
const int MAXN=20;
#define LL long long

LL digit[MAXN],dp[MAXN][10],n;//dp[len][k]:len数位有连续几个6

LL DFS(LL pos ,LL sum, bool limit)
{
  if(pos==-1)
    return sum==3;
  if(!limit && dp[pos][sum]!=-1)
    return dp[pos][sum];
  LL ans=0,cnt;
  LL up=limit ? digit[pos]:9;
  for(int i=0; i<=up; i++)
  {
    if(sum==3)           //出现了连续3个6
      cnt=3;
    else if(i==6)
      cnt=sum+1;
    else
      cnt=0;
    ans+=DFS(pos-1, cnt, limit && (i==up));
  }
  if(!limit)
    dp[pos][sum]=ans;
  return ans;
}

LL Cal(LL x)
{
  memset(dp,-1,sizeof(dp));//奇怪必须要放在这里
  LL pos = 0;
  while(; x; x/=10)
    digit[pos ++] = x %10;
  return DFS(pos-1, 0, 1);
}

int main()
{
  //freopen("revelation.in","r",stdin);
  //freopen("revelation.out","w",stdout);
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%lld",&n);
    LL l=666LL,r=100000000000LL;
    while(l < r)
    {
      LL mid=(l+r)>>1;
      LL temp=Cal(mid);
      temp>=n? r=mid:l=mid+1;//奇怪这里不能直接用calc()
    }
    printf("%lld\n",l);
  }
  return 0;
}

