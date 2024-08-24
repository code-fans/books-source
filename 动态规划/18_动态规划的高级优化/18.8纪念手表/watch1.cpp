#include <bits/stdc++.h>
using namespace std;
const int maxV=100005;
const int maxn=105;
int c[maxn],w[maxn];
int n,V;
bool dp[maxV];

void ZeroOnePack(int cost)
{
  for(int i=V; i>=cost; i--)
    dp[i]|=dp[i-cost];
}


void CompletePack(int cost)
{
  for(int i=cost; i<=V; i++)
    dp[i]|=dp[i-cost];
}


void MultiplePack()
{
  for(int i=1; i<=n; i++)
  {
    if(w[i]*c[i]>=V)CompletePack(w[i]);
    else
    {
      int k=1;
      while(k<c[i])
      {
        ZeroOnePack(k*w[i]);
        c[i]-=k;
        k<<=1;
      }
      ZeroOnePack(c[i]*w[i]);
    }
  }
}

int main()
{
  //freopen("watch10.in","r",stdin);
  //freopen("watch10.ans","w",stdout);
  while(scanf("%d%d",&n,&V)&&n&&V)
  {
    for(int i=1; i<=n; i++)
      cin>>w[i];
    for(int i=1; i<=n; i++)
      cin>>c[i];
    for(int i=0; i<=V; i++)
      dp[i]=0;
    dp[0]=1;
    MultiplePack();
    int ans=0;
    for(int i=1; i<=V; i++)if(dp[i])ans++;
    printf("%d\n",ans);
  }
  return 0;
}

