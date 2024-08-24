//迷宫 - STL实现BFS
#include <bits/stdc++.h>
using namespace std;
#define N 105

struct M
{
  int  x,y;
  bool vis;                                     //走过则标记为1以防走回去
} pre[N][N];
bool Map[N][N];                                 //保存地图
int m,n;
int dir[8][2]= {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};

bool In(int x,int y)                            //判断坐标是否越界
{
  return (x>0 && x<=m && y>0 && y<=n);
}

void PrintWay(int x,int y)                      //递归输出路径
{
  if (x==1 && y==1)
    printf("%d %d\n",x,y);
  else
  {
    PrintWay(pre[x][y].x,pre[x][y].y);
    printf("%d %d\n",x,y);
  }
}

void BFS()
{
  queue<M>q;                                    //定义一个队列
  q.push(M {1,1});                              //入队列,注意这是C++11写法
  pre[1][1].vis=true;                           //起始点坐标标记为已走过
  while (!q.empty())
  {
    M cur=q.front();
    q.pop();                                    //出队列
    if(cur.x==m && cur.y==n)                    //找到出口
    {
      PrintWay(m,n);
      exit(0);
    }
    for (int i=0; i<=7; i++)                    //尝试八个方向
    {
      int x=cur.x+dir[i][0];
      int y=cur.y+dir[i][1];
      if (In(x,y) && !pre[x][y].vis && !Map[x][y])//如果该坐标可走
      {
        q.push(M {x,y});                        //坐标入队，C++11写法
        pre[x][y].x=cur.x;                      //存入上一步的坐标
        pre[x][y].y=cur.y;
        pre[x][y].vis=true;
      }
    }
  }
}

int main()
{
  cin>>m>>n;
  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      scanf("%d",&Map[i][j]);
  BFS();
  puts("-1");
  return 0;
}

