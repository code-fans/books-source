#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[10005],q[10005],dp[10005][5005];          //dp[i][j]前i个数分成j段
int in(int k1,int k2,int ai,int j)
{
  int x1,x2;
  x1=dp[k1][j-1]-dp[k2][j-1]+a[k1+1]*a[k1+1]-a[k2+1]*a[k2+1];
  x2=2*ai*(a[k1+1]-a[k2+1]);
  if(x1>=x2)
    return 1;
  return 0;
}
int out(int k1,int k,int k2,int j)
{
  int x1,x2;
  x1=(dp[k1][j-1]-dp[k][j-1]+a[k1+1]*a[k1+1]-a[k+1]*a[k+1])*(a[k+1]-a[k2+1]);
  x2=(dp[k][j-1]-dp[k2][j-1]+a[k+1]*a[k+1]-a[k2+1]*a[k2+1])*(a[k1+1]-a[k+1]);
  if(x1>=x2)
    return 1;
  return 0;
}
int main()                                      //设k1<k2，假设k1比k2优,所以
{
  //freopen("subset.in","r",stdin);
  //freopen("subset.out","w",stdout);
  int t,n,m,i,j,l,r,k,k1,k2,cas;              //dp[k1][j-1]+(a[i]-a[k1+1])^2<dp[k2][j-1]+(a[i]-a[k2+1])^2
  scanf("%d",&t);                             //(dp[k1][j-1]-dp[k2][j-1]+a[k1+1]^2-a[k2+1]^2)/(2*(a[k1+1]-a[k2+1]))>=a[i]
  for(cas=1; cas<=t; cas++)                   //设左式为G(k1,k2)
  {
    scanf("%d%d",&n,&m);                    //当G(k1,k2)>=a[i]时 k1较优，当G(k1,k2)<=a[i]时 k2较优
    for(i=1; i<=n; i++)                     //由这些条件还可以推出当k1<k<k2，G(k1,k)>=G(k,k2)时选择k1
      scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(i=1; i<=n; i++)
      dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
    for(j=2; j<=m; j++)
    {
      l=r=0;
      q[0]=j-1;
      for(i=j; i<=n; i++)
      {
        while(r-l>0)
        {
          k1=q[l],k2=q[l+1];
          if(in(k1,k2,a[i],j))
            l++;
          else
            break;
        }
        dp[i][j]=dp[q[l]][j-1]+(a[i]-a[q[l]+1])*(a[i]-a[q[l]+1]);
        while(r-l>0)
        {
          k1=q[r-1],k=q[r],k2=i;
          if(out(k1,k,k2,j))
            r--;
          else
            break;
        }
        q[++r]=i;
      }
    }
    printf("Case %d: %d\n",cas,dp[n][m]);
  }
  return 0;
}
