//取款机-简单的多重背包
#include <bits/stdc++.h>
using namespace std;

int w[110],dp[100010];                //dp[j]表示cash为j时能得到的最大金额

int main()
{
  //freopen("cash.in","r",stdin);
  //freopen("cash.out","w",stdout);
  int cash,N,n,d;
  while(scanf("%d%d",&cash,&N)!=EOF)
  {
    memset(dp,0,sizeof(dp));
    int count = 1;
    for(int i=1; i<=N; i++)
    {
      scanf("%d%d",&n,&d);
      for(int j=1; j<=n; j<<=1)       //j左移一位，进行二进制拆分
      {
        w[count++]=j*d;               //价值乘上相应的二进制系数
        n-=j;
      }
      if(n>0)                         //剩余未拆分的
        w[count++]=n*d;
    }
    for(int i=1; i<count; i++)        //转为01背包
      for(int j=cash; j>=w[i]; j--)
        dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
    printf("%d\n",dp[cash]);
  }
  return 0;
}

