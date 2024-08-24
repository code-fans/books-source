//复杂的审批
#include <bits/stdc++.h>
using namespace std;

int n,m,End;
int Map[105][505],f[105][505];

void DFS(int x,int y)                                 //DFS输出路径
{
  if(x==1)
  {
    printf("%d\n",y);
    return;
  }
  if(f[x-1][y]+Map[x][y]==f[x][y])
    DFS(x-1,y);
  else if(f[x][y-1]+Map[x][y]==f[x][y])
    DFS(x,y-1);
  else
    DFS(x,y+1);
  printf("%d\n",y);
}

int main()
{
  //freopen("approval.in","r",stdin);
  //freopen("approval.out","w",stdout);
  memset(f,127/2,sizeof(f));
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      scanf("%d",&Map[i][j]);
  for(int i=1; i<=m; i++)                             //第一层的特殊处理
    f[1][i]=Map[1][i];
  for(int i=2; i<=n; i++)                             //从第二层开始动规
  {
    for(int j=1; j<=m; j++)
      f[i][j]=f[i-1][j]+Map[i][j];
    for(int j=2; j<=m; j++)
      f[i][j]=min(f[i][j],f[i][j-1]+Map[i][j]);
    for(int j=m-1; j>=1; j--)
      f[i][j]=min(f[i][j],f[i][j+1]+Map[i][j]);
  }
  for(int i=1,Min=1e9; i<=m; i++)                     //找到最小值
    if(f[n][i]<Min)
    {
      Min=f[n][i];
      End=i;
    }
  DFS(n,End);
  return 0;
}
