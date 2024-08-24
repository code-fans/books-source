#include <bits/stdc++.h>
using namespace std;

int dp[20][5],ans[20];
int main()
{
  //freopen("revelation1.in","r",stdin);
  //freopen("revelation1.ans","w",stdout);
  int i,j,k,m,n,p,q,x,y,z,T,now,cnt,tot;
  dp[0][0]=1;
  for (i=0; i<=15; i++)
    for (j=0; j<=3; j++)
    {
      dp[i+1][j==3?3:j+1]+=dp[i][j];
      dp[i+1][j==3?3:0]+=dp[i][j]*9;
    }
  scanf("%d",&T);
  while (T--)
  {
    memset(ans,0,sizeof(ans));
    scanf("%d",&x);
    p=3;
    while (dp[p][3]<x) p++;
    now=cnt=0;
    for (i=p; i>=1; i--)
    {
      for (j=0; j<=9; j++)
      {
        y=cnt;
        if (cnt<3)
        {
          if (j==6) cnt++;
          else cnt=0;
        }
        tot=now;
        for (k=3; k>=0; k--)
          if (cnt+k>=3) tot+=dp[i-1][k];
        if (tot>=x)
        {
          ans[i]=j;
          break;
        }
        now=tot;
        cnt=y;
      }
    }
    for (i=p; i>=1; i--)
      printf("%d",ans[i]);
    printf("\n");
  }
}

