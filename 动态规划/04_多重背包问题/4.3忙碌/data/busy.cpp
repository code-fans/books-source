//忙碌
#include <bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;

int dp[110][110],cost[110],val[110];

int main()
{
  freopen("busy.in","r",stdin);
  freopen("busy.out","w",stdout);
  int n,t,m,s;
  scanf("%d%d",&n,&t);
  for(int i=1; i<=n; i++)
  {
    scanf("%d%d",&m,&s);
    for(int j=1; j<=m; j++)
      scanf("%d%d",&cost[j],&val[j]);
    for(int j=0; j<=t; j++)
      dp[i][j]=(s==0 ? -INF : dp[i-1][j]);
    for(int j=1; j<=m; j++)
      for(int k=t; k>=cost[j]; k--)
        if(s==1)                        //最多完成一项工作
          dp[i][k]=max(dp[i][k],dp[i-1][k-cost[j]]+val[j]);
        else
        {
          dp[i][k]=max(dp[i][k],dp[i][k-cost[j]]+val[j]);
          dp[i][k]=max(dp[i][k],dp[i-1][k-cost[j]]+val[j]);
        }
  }
  printf("%d\n",max(dp[n][t],-1));//因0类的存在,可能达不到要求,比-1小输出-1
  return 0;
}
