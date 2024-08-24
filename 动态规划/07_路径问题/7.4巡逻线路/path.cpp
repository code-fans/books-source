//因为这个可以看成一个无向图，所有我们可以将路径分为去和回两条，
//然后把回去的路径反过来，这就变成了求两条路径覆盖所有点并且不
//重复还有两个特殊点。
//用dp[i][j]表示第一条路径到达第i个点，第二条路径到达第j个点时的
//最短路。然后我们每次让i和j交替向前，用一个k表示第i和第j个点先前走的最近距离
//定义k为max(i,j)+1;这是
//为了保证更新时不会更新出F[i][i](即一个点走了两次)，而且每个点都会在路径上，
//我们每次用F[i][j]去更新点max(i,j)+1，
//  dp[1][1]=0;
//转移方程为：
//  dp[i][k]=min(dp[i][k],dp[i][j]+dis[j][k]);
//  dp[k][j]=min(dp[k][j],dp[i][j]+dis[i][k]);
//最终任意一条路径到达终点时
//dp[n][n]=min(dp[n][n],dp[i][j]+dis[i][n])
//dp[n][n]=min(dp[n][n],dp[i][j]+dis[j][n])

#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define INF 0x3f3f3f3f

double x[N],y[N],dis[N][N],dp[N][N];

double Dis(double x1,double y1,double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
  //freopen("path.in","r",stdin);
  //freopen("path.out","w",stdout);
  int n,b1,b2;
  scanf("%d%d%d",&n,&b1,&b2);
  b1++;
  b2++;
  for (int i=1; i<=n; i++)
    scanf("%lf%lf",&x[i],&y[i]);
  for (int i=1; i<n; i++)
    for (int j=i+1; j<=n; j++)
      dis[i][j]=dis[j][i]=Dis(x[i],y[i],x[j],y[j]);  //计算距离
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      dp[i][j]=INF;                                  //初始化
  dp[1][1]=0;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
      if (i==j && i!=1)                              //两条路不能重复且不是第一个点
        continue;
      int k=max(i,j)+1;                              //i,j交替向前
      if (k==n+1)                                    //到达终点时
      {
        if (i!=n)
          dp[n][n]=min(dp[n][n],dp[i][j]+dis[i][n]);
        if (j!=n)
          dp[n][n]=min(dp[n][n],dp[i][j]+dis[j][n]);
      }
      else                                           //没有到达终点时
      {
        if (k!=b1)                                   //把b1排除在第二条路外
          dp[i][k]=min(dp[i][k],dp[i][j]+dis[j][k]);
        if (k!=b2)                                   //把b2排除在第一条路外
          dp[k][j]=min(dp[k][j],dp[i][j]+dis[i][k]);
      }
    }
  printf("%0.2lf\n",dp[n][n]);
  return 0;
}
