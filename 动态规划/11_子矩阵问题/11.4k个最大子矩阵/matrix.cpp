//f[i][j][k]表示第一列处理到第i个，第二列处理到第j个并且选取了k个子矩阵的最优值。
//转移的话要不从左边（第一列）选择一块，要不从右边（第二列）选择一块，又或者
//两列都占的矩形，但是只有i、j相等才可能两列都占，否则无法刚好到达i。
//luguo 2331
#include<bits/stdc++.h>
using namespace std;

int dp[150][11],f[150][150][11];
int sum[2][150];

int main()
{
  int n,m,k,t1,t2;
  cin>>n>>m>>k;
  if(m==1)                        //特判只有一列的情况,这个分无论如何要拿到
  {
    for(int i=1; i<=n; i++)
    {
      cin>>t1;
      sum[0][i]=sum[0][i-1]+t1;   //前缀和
    }
    for(int K=1; K<=k; K++)       //枚举子矩阵个数
      for(int j=0; j<=n; j++)     //dp[i][k]表示到第i行，选了k个子矩阵的最值
        for(int i=j; i<=n; i++)   //枚举行
          dp[i][K]=max(dp[i][K],max(dp[j][K-1]+sum[0][i]-sum[0][j],dp[i-1][K]));//选，不选 
    printf("%d\n",dp[n][k]);
  }
  else
  {
    for(int i=1; i<=n; i++)
    {
      cin>>t1>>t2;
      sum[0][i]=sum[0][i-1]+t1;     //sum[0][i]表示第一列的前缀和
      sum[1][i]=sum[1][i-1]+t2;     //sum[1][i]表示第二列的前缀和
    }
    for(int l=1; l<=k; l++)         //选k个矩阵的k在最外层
      for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
          //f[i][j][k]表示第一列处理到第i个，第二列处理到第j个并且选取了k个子矩阵的最优值
          f[i][j][l]=max(f[i-1][j][l],f[i][j-1][l]);
          for(int s=0; s<i; s++)
            f[i][j][l]=max(f[i][j][l],f[s][j][l-1]+sum[0][i]-sum[0][s]); //枚举从左边转移
          for(int s=0; s<j; s++)
            f[i][j][l]=max(f[i][j][l],f[i][s][l-1]+sum[1][j]-sum[1][s]); //枚举从右边转移
          if(i==j)
            for(int s=0; s<i; s++)                                       //枚举从两边转移
              f[i][j][l]=max(f[i][j][l],f[s][s][l-1]+sum[0][i]-sum[0][s]+sum[1][j]-sum[1][s]);
        }
    printf("%d\n",f[n][n][k]);
  }
  return 0;
}
