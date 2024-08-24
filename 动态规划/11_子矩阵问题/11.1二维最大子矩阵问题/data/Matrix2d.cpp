//二维最大子矩阵问题
#include <bits/stdc++.h>
using namespace std;

int sum[201][201],temp[201];          //其实可以无需定义temp[]
int n,m;

int Solve()
{
  int Max=-INT_MAX;
  for(int i=0; i<=n; i++)             //从i行
    for(int j=i+1; j<=n; j++)         //到j行
    {
      for(int k=1; k<=m; k++)         //求出i到j行第k列的和
        temp[k]=sum[j][k]-sum[i][k];
      int sumall=0;
      for(int k=1; k<=m; k++)         //与最大子序列和一样，找到最大值
      {
        sumall+=temp[k];
        Max=max(Max,sumall);          //更新最大值
        if(sumall<0)                  //累加值为负数,则清零再累计
          sumall=0;
      }
    }
  return Max;
}

int main()
{
  freopen("Matrix2d.in","r",stdin);
  freopen("Matrix2d.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1,x; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      scanf("%d",&x);
      sum[i][j]=sum[i-1][j]+x;        //压缩数据
    }
  printf("%d\n",Solve());
  return 0;
}

