//友好城市
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

int ans,dp[5010],n;

struct node
{
  int c,d;
} p[5010];

int Cmp(node a,node b)
{
  return a.c<b.c;
}

int main()
{
  freopen("city.in","r",stdin);
  freopen("city.out","w",stdout);
  scanf("%*d%*d%d",&n,&n,&n);      //x,y是无用的
  for(int i=1; i<=n; i++)
    scanf("%d%d",&p[i].c,&p[i].d);
  sort(p+1,p+n+1,Cmp);
  for(int i=1; i<=n; i++)
    for(int j=0; j<i; j++)
      if(p[i].d>p[j].d)
        dp[i]=max(dp[i],dp[j]+1);
  for(int i=1; i<=n; i++)
    ans=max(ans,dp[i]);
  printf("%d\n",ans);
  return 0;
}

