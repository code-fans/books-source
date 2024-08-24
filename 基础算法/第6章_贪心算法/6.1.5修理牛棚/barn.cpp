/*
程序名称：USACO 1.3.2 Barn1
程序说明：动态规划
设d[i,j]表示第i个牛修到第j个牛需要使用的木板长度,
设f[i,j]表示用前i个木版修到第j头牛所用的最短长度.
 f[i,j]=min(f[i-1,k-1]+d[k,j])  (1<=k<=j)
显然d[i,j]=cow[j]-cow[i]+1,f[1,i]=d[1,i]
*/
#include <bits/stdc++.h>
using namespace std;
const int INF= (1<<30);

int m,c,s,cow[201],d[201][201],f[51][201];

int main()
{
  freopen ("barn.in","r", stdin);
  freopen ("barn.out","w",stdout);
  cin>>m>>s>>c;
  for(int i=1; i<=c; i++)
    cin>>cow[i];
  sort(cow+1,cow+1+c);        //由左到右排好序
  memset(f,127,sizeof(f));    //初始为最大值
  for(int i=1; i<=c; i++)     //计算覆盖第i头牛到第j头牛所需的木板长度
    for(int j=1; j<=c; j++)
      d[i][j] = abs(cow[i]-cow[j])+1;
  for(int i=1; i<=c; i++)     //边界条件
    f[1][i] = d[1][i];
  for(int i=1; i<=m; i++)     //没这个边界条件会有两个点过不去
    f[i][0] = 0;
  for(int i=1; i<=m; i++)     //动态规划,枚举木板数量
    for(int j=1; j<=c; j++)   //左从到右枚举牛
      for(int k=1; k<=j; k++) //k在1~j范围内尝试
        f[i][j]=min(f[i][j],f[i-1][k-1]+d[k][j]);
  cout<<f[m][c]<<"\n";
  return 0;
}

