//简单背包问题 - 递归解法
#include <bits/stdc++.h>
using namespace std;

int W[40];               //各物品重量

int Bag(int s,int n)     //s为剩余重量，n为剩余可选物品数
{
  if(s==0)               // 如果正好装满
    return 1;
  if(s<0||(s> 0 && n<1)) //如s<0或n<1则不能完成
    return 0;
  if(Bag(s-W[n],n-1))    //从后往前装，装上W[n]后，若剩余物品仍有解
  {
    cout<<W[n]<<"\n";    //则装进第n个包，并输出
    return 1;
  }
  return Bag(s,n-1);     //如装了第n个后无解则删除，尝试第n－1个
}

int main()
{
  freopen("Backpack.in","r",stdin);
  freopen("Backpack.out","w",stdout);
  int S,N;
  scanf("%d%d",&S,&N);
  for(int i=1; i<=N; ++i)
    scanf("%d",&W[i]);
  if(!Bag(S,N))
    printf("Failed!\n");
  return 0;
}

