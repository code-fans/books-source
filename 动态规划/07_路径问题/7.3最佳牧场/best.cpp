#include<bits/stdc++.h>
const int inf=0x3fffffff;
using namespace std;
int n,m,p,like[501];//n个点，m条边，p个喜欢的点（因为本人习惯，与题目中有所不同）
int ans,mi=inf,f[501][501];
int main()
{
  int i,j,k,u,v,c,sum;
  cin>>n>>p>>m;
  for(i=1; i<=n; i++) //初始化
  {
    for(j=1; j<=n; j++) f[i][j]=inf;
    f[i][i]=0;//点i到点i的最小距离为0
  }
  for(i=1; i<=p; i++) cin>>like[i];
  for(i=1; i<=m; i++)
  {
    cin>>u>>v>>c;
    f[u][v]=c;//采用类似邻接矩阵的方式读入
    f[v][u]=c;
  }
  for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);//DP动态转移方程
  for(i=1; i<=n; i++)
  {
    sum=0;
    for(j=1; j<=p; j++) sum+=f[i][like[j]]; //累加距离和
    if(sum<mi)
    {
      mi=sum;  //更新答案
      ans=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}
