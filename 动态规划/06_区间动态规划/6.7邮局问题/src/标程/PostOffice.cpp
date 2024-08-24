//邮局问题
#include<bits/stdc++.h>
using namespace std;

int dp[310][31],sum[310][310],pos[310];

int main()
{
  //freopen("PostOffice.in","r",stdin);
  //freopen("PostOffice.out","w",stdout);
  int V,P;
  cin>>V>>P;
  for(int i=1; i<=V; ++i)
    cin>>pos[i];
  for(int i=1; i<V; i++)
    for(int j=i+1; j<=V; j++)
      sum[i][j]=sum[i][j-1]+pos[j]-pos[(i+j)/2];
  for(int i=1; i<=V; ++i)
  {
    dp[i][i]=0;
    dp[i][1]=sum[1][i];
  }
  for(int j=2; j<=P; ++j)                  //枚举邮局 
    for(int i=j+1; i<=V; ++i)              //枚举村庄 
    {
      dp[i][j]=0x3f3f3f3f;
      for(int k=j-1; k<i; ++k)
        dp[i][j]=min(dp[i][j],dp[k][j-1]+sum[k+1][i]);
    }
  cout<<dp[V][P]<<'\n';
  return 0;
}

