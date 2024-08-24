//分组背包问题，思路是把每一组看做一个物品，转化为01背包做
//三重循环，组数在最外层，枚举容量在中间层，某组物品枚举在最内层
//这可以保证一个组中要么选一个要么不选。
//因为我们是通过枚举物品来向容量转移，容量是不变的，变的是物品的品种，
//并且，最终只会转移一个所以就保证了分组背包的原则。
#include <bits/stdc++.h>
using namespace std;

int m,n,p,K;
int w[10001],c[10001],f[10001],stone[10001][1001];

int main()
{
  freopen("kbag.in","r",stdin);
  freopen("kbag.out","w",stdout);
  scanf("%d%d",&m,&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d%d%d",&w[i],&c[i],&p);
    stone[p][++stone[p][0]]=i;
    K=max(K,p);                          //统计最多有多少组
  }
  for(int k=1; k<=K; k++)                //枚举组数
    for(int j=m; j>=0; j--)              //倒序枚举背包容量
      for(int i=1; i<=stone[k][0]; i++)  //枚举k组里的所有物品
        if(w[stone[k][i]]<=j)            //如果可以放
          f[j]=max(f[j],f[j-w[stone[k][i]]]+c[stone[k][i]]);
  printf("%d\n",f[m]);
}
