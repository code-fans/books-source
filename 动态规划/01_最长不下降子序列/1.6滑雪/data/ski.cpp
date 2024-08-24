//滑雪
#include <bits/stdc++.h>
using namespace std;

const int dx[4]= {-1,0,1,0};         //x的增量坐标
const int dy[4]= {0,1,0,-1};         //y的增量坐标
int m[101][101],f[101][101];
int r,c;

int Search(int x,int y)              //求到[x,y]点的最长路径
{
  if(f[x][y]>0)                      //如此点出发的长度已求出
    return f[x][y];                  //则无需递归
  f[x][y]=1;                         //自身初始长度就是1
  for(int i=0; i<=3; i++)            //从四个点搜索能到达[x,y]的点
  {
    int nx=x+dx[i];                  //加上横坐标增量
    int ny=y+dy[i];                  //加上纵坐标增量
    if(nx>=1 && nx<=r && ny>=1 && ny<=c && m[x][y]<m[nx][ny])
      f[x][y]=max(Search(nx,ny)+1,f[x][y]);      //递归进行记忆化搜索
  }
  return f[x][y];
}

int main()
{
  freopen("ski.in","r",stdin);
  freopen("ski.out","w",stdout);
  scanf("%d%d",&r,&c);
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
      scanf("%d",&m[i][j]);
  int ans=0;
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
    {
      f[i][j]=Search(i,j);
      ans=max(f[i][j],ans);
    }
  printf("%d\n",ans);
  return 0;
}

