//扩展最大子矩阵问题
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1001;

int n,m;
int a[MAXN][MAXN],sum[MAXN][MAXN];

int GetMax(int begin, int end,int m)
{
  int Max=-INT_MAX;
  for(int i=begin; i<=end; i++)
    for(int j=i+1; j<=end; j++)
    {
      int sumall=0;
      for(int k=1; k<=m; k++)
      {
        sumall+=sum[j][k]-sum[i][k];
        Max=max(sumall,Max);
        if(sumall<0)
          sumall=0;
      }
    }
  return Max;
}

int Cut(int n,int m)
{
  int Max=-INT_MAX;
  for(int t=1; t<=n; ++t)                     //枚举横切的位置
    Max=max(Max,GetMax(0,t,m)+GetMax(t,n,m)); //上矩阵和下矩阵的最优解
  return Max;
}

int main()
{
  freopen("supermatrix.in","r",stdin);
  freopen("supermatrix.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    {
      scanf("%d",&a[i][j]);
      sum[i][j]=sum[i-1][j]+a[i][j];
    }
  int max1=Cut(n,m);                          //求横切的最优解

  memcpy(sum,a,sizeof(a));
  for(int i=1; i<=n; ++i)                     //将矩阵旋转90度
    for(int j=1; j<=m; ++j)
      a[j][i]=sum[i][j];
  for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j)
      sum[i][j]=sum[i-1][j]+a[i][j];
  int max2=Cut(m,n);                          //求纵切的最优解
  printf("%d\n",max(max1,max2));
  return 0;
}

