//迷宫问题 - 深度优先递归算法
#include <bits/stdc++.h>
using namespace std;
#define N 105
bool Map[N][N];
int path[N][N];
int n,m;
int dir[8][2]= {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

bool In(int x,int y)
{
  return (x>0 && x<=m && y>0 && y<=n);
}

int DFS(int x,int y,int last)
{
  path[x][y]=last;                                 //前驱last存入
  if(x==m && y==n)
    return 1;
  for(int i=0; i<=7; i++)                          //查找相邻坐标
  {
    int xx=x+dir[i][0];
    int yy=y+dir[i][1];
    if(In(xx,yy) && !path[xx][yy] && !Map[xx][yy] )
      if(DFS(xx,yy,i+1))
        return 1;
  }
  return 0;
}

void PrintWay(int x,int y)
{
  if(y==1 && x==1)
    cout<<1<<" "<<1<<endl;
  else
  {
    int u=path[x][y]-1;
    PrintWay(x-dir[u][0],y-dir[u][1]);
    cout<<x<<" "<<y<<endl;
  }
}

int main()
{
  //freopen("labyrinth.in","r",stdin);
  //freopen("labyrinth.out","w",stdout);

  cin>>m>>n;
  for(int i=1; i<=m; i++)
    for(int j=1; j<=n; j++)
      cin>>Map[i][j];
  if(DFS(1,1,0))
    PrintWay(m,n);
  else
    puts("-1");
  return 0;
}

