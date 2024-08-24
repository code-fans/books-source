//分组背包问题，思路是把每一组看做一个物品，转化为01背包做
//三重循环，组数在最外层，枚举容量在中间层，某组物品枚举在最内层
//这可以保证一个组中要么选一个要么不选。
//因为我们是通过枚举物品来向容量转移，容量是不变的，变的是物品的品种，
//并且，最终只会转移一个所以就保证了分组背包的原则。
#include <bits/stdc++.h>
using namespace std;

int stone[1001],w[1001],f[1001],ID[101][1001];

int main()
{
  freopen("kbag.in","r",stdin);
  freopen("kbag.out","w",stdout);
  int m,n,K;
  scanf("%d%d",&m,&n);
  for(int i=1,c; i<=n; i++)
  {
    scanf("%d%d%d",&stone[i],&w[i],&c);
    ID[c][++ID[c][0]]=i;               //ID[c][x]保存c组第x个石头的编号
    K=max(K,c);                        //K确定最多有多少组
  }
  for(int k=1; k<=K; k++)              //枚举组别,放在循环最外面
    for(int j=m; j>=0; j--)            //背包容量逆循环,在枚举k组物品之上
      for(int i=1; i<=ID[k][0]; i++)   //枚举k组所有物品
        if(stone[ID[k][i]]<=j)         //如果可以放
          f[j]=max(f[j],f[j-stone[ID[k][i]]]+w[ID[k][i]]);
  printf("%d\n",f[m]);
  return 0;
}

