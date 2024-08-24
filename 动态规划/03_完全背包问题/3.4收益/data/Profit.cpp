//收益
//因为基金都是1000的倍数，所以把m和基金的花费
//都缩小1000去进行背包求解，得到的解用未缩小的
//总钱数去加，然后再缩小1000去求解下一年的。
//本金不是1000的整倍数也不会影响结果
#include <bits/stdc++.h>
using namespace std;

int T,amount,n,d;
int weight[12],profit[12],dp[1000002];

int main()
{
  freopen("Profit.in","r",stdin);
  freopen("Profit.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&amount,&n,&d);
    for (int i=0; i<d; i++)
    {
      scanf("%d%d",&weight[i],&profit[i]);
      weight[i] /= 1000;
    }
    for (int i=0; i<n; i++)              //枚举每一年
    {
      int t = amount/1000;
      for (int j=0; j<d; j++)            //枚举每一个债券
        for (int k=weight[j]; k<=t; k++) //枚举背包容量（价值）
          dp[k]=max(dp[k],dp[k-weight[j]]+profit[j]);
      amount += dp[t];                   //每年结束，要更新手中的钱
    }
    printf("%d\n",amount);
  }
  return 0;
}

