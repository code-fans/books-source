//收服精灵
#include <bits/stdc++.h>
using namespace std;
int M,K,n,Max=-1;
int dp[1050][700],m[1050],k[1050];

int main()
{
  freopen("fairy.in","r",stdin);
  freopen("fairy.out","w",stdout);
  scanf("%d%d%d",&M,&K,&n);
  for(int i=1; i<=n; i++)
    scanf("%d%d",&m[i],&k[i]);
  for(int i=1; i<=n; i++)
    for(int j=M; j>=m[i]; j--)//数量 
      for(int p=K; p>=k[i]; p--)//伤害 
        dp[j][p]=max(dp[j][p],dp[j-m[i]][p-k[i]]+1);
  int Ans=K;
  for(int i=0; i<=K; i++)
    if(dp[M][i]>Max)
    {
      Max=dp[M][i];
      Ans=K-i;
    }
  printf("%d %d\n",Max,Ans);
  return 0;
}

