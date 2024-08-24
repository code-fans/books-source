//多重背包 -  DP
#include <bits/stdc++.h>
using namespace std;

int n[101],w[101],c[101],dp[101];

int main()
{
  //freopen("Mbag.in","r",stdin);
  //freopen("Mbag.out","w",stdout);
  int V,N,ans=1e-9;
  scanf("%d%d",&V,&N);
  for(int i=0; i<N; i++)
    scanf("%d%d%d",&c[i],&w[i],&n[i]);
  for(int i=0; i<N; i++)                        //n种石头
    for(int j=0; j<n[i]; j++)                   //不超过该石头个数
      for(int k=V; k>=c[i]; k--)                //枚举包的重量
      {
        dp[k]=max(dp[k],dp[k-c[i]]+w[i]);
        ans=max(dp[k],ans);
      }
  printf("%d\n",ans);
  return 0;
}

