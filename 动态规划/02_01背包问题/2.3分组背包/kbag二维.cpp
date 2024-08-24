//分组背包—动规算法1
#include<bits/stdc++.h>
using namespace std;

int V,N,w[101][1001],f[101][1001],stone[111][1001],K=0;

int main()
{
  //freopen("kbag.in","r",stdin);
  //freopen("kbag.out","w",stdout);
  cin>>V>>N;
  for(int i=1,a,b,c; i<=N; i++)
  {
    cin>>a>>b>>c;
    stone[c][++stone[c][0]]=a;            //stone[i][0]存放c组物品个数
    w[c][stone[c][0]]=b;                  //w[i][j]存第i组第j个物品的价值
    K=max(K,c);                           //统计最多有多少组
  }
  for(int k=1; k<=K; k++)                 //枚举分组
    for(int i=0; i<=stone[k][0]; i++)     //枚举该分组里的物品
      for(int j=V; j>=stone[k][i]; j--)   //枚举背包容量
        f[k][j]=max(f[k-1][j],max(f[k-1][j-stone[k][i]]+w[k][i],f[k][j]));
  printf("%d\n",f[K][V]);
  return 0;
}
