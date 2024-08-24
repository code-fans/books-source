//封闭面积问题
#include<bits/stdc++.h>
using namespace std;
int Map[11][11];
int dx[4]= {1,0,-1,0};                               //建立方向偏移数组
int dy[4]= {0,-1,0,1};

void BFS(int x, int y)
{
  queue <int> X,Y;                                   //此处使用STL里的queue
  Map[x][y] = 1;
  X.push(x);
  Y.push(y);
  while(!X.empty())
  {
    for(int i=0; i<=3; ++i)                          //寻找相邻的区域 
    {
      int xx=X.front()+dx[i];
      int yy=Y.front()+dy[i];
      if(!Map[xx][yy] && xx>0 && xx<=10 && yy>0 && yy<=10)
      {
        Map[xx][yy]=1;
        X.push(xx);
        Y.push(yy);
      }
    }
    X.pop();
    Y.pop();
  }
}

int main()
{
  //freopen("area.in", " r", stdin);
  //freopen("area.out", "w", stdout);
  for(int i = 1; i <= 10; ++i)
    for(int j = 1; j <= 10; ++j)
      scanf("%d", &Map[i][j]);
  for(int i = 1; i <= 10; ++i)                      
  {
    if(!Map[i][1])  BFS(i, 1);
    if(!Map[i][10]) BFS(i, 10);
    if(!Map[1][i])  BFS(1, i);
    if(!Map[10][i]) BFS(10, i);
  }
  int ans=0;
  for(int i = 1; i <= 10; ++i)
    for(int j = 1; j <= 10; ++j)
      if(!Map[i][j])
        ans++;
  printf("%d\n", ans);
  return 0;
}
