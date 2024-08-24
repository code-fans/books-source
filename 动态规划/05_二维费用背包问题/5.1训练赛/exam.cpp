//ÑµÁ·Èü
#include <bits/stdc++.h>
using namespace std;

int t[110],v[110],g[110];
int dp[1100][110];

int main()
{
  freopen("exam.in","r",stdin);
  freopen("exam.out","w",stdout);
  int T,V,N;
  scanf("%d%d%d",&T,&V,&N);
  for(int i=1; i<=N; ++i)
    scanf("%d%d%d",&g[i],&t[i],&v[i]);
  for(int i=1; i<=N; ++i)                                  //Ã¶¾ÙÎïÆ·
    for(int j=T; j>=t[i]; --j)                             //ÄæÐòÃ¶¾Ù×´Ì¬1
      for(int k=V; k>=v[i]; --k)                           //ÄæÐòÃ¶¾Ù×´Ì¬2
        dp[j][k]=max(dp[j][k],dp[j-t[i]][k-v[i]]+g[i]);
  printf("%d\n",dp[T][V]);
  return 0;
}

