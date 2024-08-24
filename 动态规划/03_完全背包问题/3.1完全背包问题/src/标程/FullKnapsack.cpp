//完全背包问题
#include <bits/stdc++.h>
using namespace std;

int m,n,c[300],w[300],f[2000];

int main()
{
  freopen("FullKnapsack.in","r",stdin);
  freopen("FullKnapsack.out","w",stdout);
  scanf("%d%d",&m,&n);
  for(int i=1; i<=n; i++)
    scanf("%d%d",&w[i],&c[i]);
  for(int v=1; v<=m; v++)
    for(int j=1; j<=n; j++)               //n个石头一个一个重复试
      if(v>=w[j])                        //如果石头可以放
        f[v]=max(f[v-w[j]]+c[j],f[v]);   //更新最大值
  printf("%d\n",f[m]);
  return 0;
}

