//多重背包 - 二进制优化算法
#include <bits/stdc++.h>
using namespace std;

int dp[201],c[50],w[50];

int main()
{
  freopen("Mbag.in","r",stdin);
  freopen("Mbag.out","w",stdout);
  int V, N,count=0;
  scanf("%d%d",&V,&N);
  for(int i=0,s,v,n; i<N; ++i)
  {
    scanf("%d%d%d",&s,&v,&n);
    for(int j=1; j<=n; j<<=1)         //j左移一位，进行二进制拆分
    {
      c[count]=j*s;                   //空间乘上相应的二进制系数
      w[count++]=j*v;                 //价值乘上相应的二进制系数
      n-=j;
    }
    if(n>0)                           //剩余未拆分的
    {
      c[count]=n*s;
      w[count++]=n*v;
    }
  }
  for(int i=0; i<count; ++i)          //01背包
    for(int j=V; j>=c[i]; --j)
      dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
  printf("%d\n",dp[V]);
  return 0;
}

