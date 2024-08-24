//¾ØÐÎÇ¶Ì×
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int l,r;
} Rec[1001];
int T,n,dp[10001],ans;
bool lin[1001][1001];

int DP(int i)
{
  if(dp[i])
    return dp[i];
  dp[i]=1;
  for(int j=1; j<=n; j++)
    if(lin[i][j])
      dp[i]=max(dp[i],DP(j)+1);
  return dp[i];
}
int main()
{
  //freopen("rec.in","r",stdin);
  //freopen("rec.out","w",stdout);
  cin>>T;
  while(T--)
  {
    memset(dp,0,sizeof(dp));
    memset(lin,0,sizeof(lin));
    memset(Rec,0,sizeof(Rec));
    cin>>n;
    for(int i=1; i<=n; i++)
      cin>>Rec[i].l>>Rec[i].r;
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        if((Rec[i].l>Rec[j].l&&Rec[i].r>Rec[j].r)||(Rec[i].l>Rec[j].r&&Rec[i].r>Rec[j].l))
          lin[i][j]=1;
    ans=0;
    for(int i=1; i<=n; i++)
      ans=max(ans,DP(i));
    cout<<ans<<endl;
  }
  return 0;
}
