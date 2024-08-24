//推棋子
#include <bits/stdc++.h>
using namespace std;

const int xx[] = {-1, 0, 1, 0};        //增量数组
const int yy[] = {0, -1, 0, 1};        //增量数组
const char u[] = {'^', '<', 'v', '>'};
char Map[10][10], o[10], p[10];

bool In(int x,int y)                   //判断是否越界
{
  return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

int main()
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  int x, y, d, step;                   //x,y为人的位置，d为前进方向
  for (int i = 1; i <= 8; ++ i)
  {
    scanf("%s", Map[i]+1);
    for (int j = 1; j <= 8; ++j)
      for (int k = 0; k < 4; ++k)
        if (Map[i][j] == u[k])
          x = i, y = j, d = k;         //获取人的坐标和方向
  }
  while (scanf("%s", o+1), o[1] != '#')//读取所有操作
  {
    if (o[1] == 'm')
    {
      int tx = x + xx[d];
      int ty = y + yy[d];
      for (scanf("%d", &step); step && In(tx, ty); --step) //当步数没走完并且没越界时
      {
        if (Map[tx][ty] != '.')                   //前方格子不是空地时
        {
          int dx=tx+xx[d];
          int dy=ty+yy[d];
          while (In(dx, dy) && Map[dx][dy] != '.')//一直找到空地，看能推多少个棋子
            dx += xx[d], dy += yy[d];           //坐标值一直累加
          while (dx != tx || dy != ty)          //前方格子的棋子一个个往前移
          {
            Map[dx][dy] = Map[dx-xx[d]][dy-yy[d]];
            dx -= xx[d];
            dy -= yy[d];
          }
        }
        Map[tx][ty] = Map[x][y];                    //对前方是空地的操作
        Map[x][y] = '.';                          //人之前的位置变为空地
        x = tx;                                 //人到了新的位置x
        y = ty;                                 //人到了新的位置y
        tx += xx[d];                            //继续试探下一步
        ty += yy[d];
      }
    }
    else
    {
      scanf("%s", p+1);
      if (p[1] == 'l')
        d = (d+1)%4;
      if (p[1] == 'r')
        d = (d+3)%4;
      if (p[1] =='b')
        d = (d+2)%4;
      Map[x][y] = u[d];                           //人的方向被改变
    }
  }
  for (int i = 1; i <=8;  ++i)
  {
    for (int j = 1; j <= 8; ++j)
      printf("%c",Map[i][j]);
    printf("\n");
  }
  return 0;
}
