//过河卒-一维优化算法
//f[i][j]=f[i-1][j]+f[i][j-1]可以写成滚动数组f[i]=f[i]+f[i-1]
//其中f[i-1]就是前面方程里的f[i][j-1]
//f[i]因为还没有被更新过,所以仍是f[i-1][j]
#include <bits/stdc++.h>
using namespace std;
const int dx[9]= {0,-2,-1,1,2,2,1,-1,-2};
const int dy[9]= {0,1,2,2,1,-1,-2,-2,-1};
long long F[21]= {1};                         //定义一维数组就可以了
bool Map[21][21];

int main()
{
  //freopen("river.in","r",stdin);
  //freopen("river.out","w",stdout);
  int n,m,x,y;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  for(int i=0; i<9; ++i)
    if(x+dx[i]>=0 && x+dx[i]<=n && y+dy[i]>=0 && y+dy[i]<=m)
      Map[x+dx[i]][y+dy[i]]=1;                //标记马能踏到的位置为1
  for(int i=0,j; i<=n; ++i)                   //从上往下逐行
    for(F[0]*=!Map[i][0],j=1; j<=m; ++j)      //每行从左向右递推
      (F[j]+=F[j-1])*=!Map[i][j];
  printf("%lld\n",F[m]);
  return 0;
}
