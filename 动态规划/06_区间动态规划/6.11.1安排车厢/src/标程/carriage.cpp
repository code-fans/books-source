//安排车厢
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define IntMax 0x3f3f3f3f

int n,m,k;
int sumb[MAXN],sumg[MAXN];
int dp[MAXN];

inline int ok(int j,int i)
{
  int sumboy = sumb[i] - sumb[j];
  int sumgirl = sumg[i] - sumg[j];
  return (i-j <= m) && (sumboy==0 || sumgirl==0 || abs(sumboy-sumgirl)<=k);
}

int main()
{
  freopen("carriage.in","r",stdin);
  freopen("carriage.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  char stu;
  for(int i = 1; i <= n; i++)                //初始化并求前序列和
  {
    cin>>stu;                                //读字符要小心
    if(stu == 'B')
    {
      sumb[i]=sumb[i-1]+1;
      sumg[i]=sumg[i-1];
    }
    if(stu == 'G')
    {
      sumg[i]=sumg[i-1]+1;
      sumb[i]=sumb[i-1];
    }
  }

  for(int i = 1; i <= n; i++)                //动规
  {
    dp[i]=IntMax;
    for(int j = 0; j < i; j++)
      if(ok(j,i) && dp[j]+1 < dp[i])
        dp[i] = dp[j]+1;
  }
  printf("%d\n",dp[n]);
  return 0;
}

