//翻转棋盘 - DFS
#include <bits/stdc++.h>
using namespace std;

int Map[6][6];                                   //棋盘,注意勿写成map
int dir[5][2]= {{-1,0},{1,0},{0,-1},{0,1},{0,0}};//周围棋子坐标偏移量
int step;
bool flag;

void Flip(int x,int y)                           //翻转（x,y）及其相邻点
{
  for(int i=0; i<=4; i++)
    Map[x+dir[i][0]][y+dir[i][1]]=!Map[x+dir[i][0]][y+dir[i][1]];//棋子翻转
}

bool OK()                                        //判断棋盘是否单色
{
  for(int i=1; i<=4; i++)
    for(int j=1; j<=4; j++)
      if(Map[i][j]!=Map[1][1])
        return false;
  return true;
}

void DFS(int x,int y,int dep)
{
  if(dep==step)
  {
    flag=OK();
  }
  if(flag||x==5)                                 //如已找到方案或枚举到最后一行末
    return ;
  Flip(x,y);                                     //翻转点(x,y)
  if(y<4)                                        //如果不是最后一列
    DFS(x,y+1,dep+1);                            //则向右移一列
  else
    DFS(x+1,1,dep+1);                            //否则跳到下一行第一列
  Flip(x,y);                                     //还原点(x,y)
  if(y<4)
    DFS(x,y+1,dep);
  else
    DFS(x+1,1,dep);
}

int main()
{
  //freopen("FlipGame.in","r",stdin);
  //freopen("FlipGame.out","w",stdout);
  char c;
  for(int i=1; i<=4; i++)
    for(int j=1; j<=4; j++)
    {
      cin>>c;
      if(c=='w')
        Map[i][j]=1;                             //白色记为1，黑色记为0
    }
  for(step=0; step<=16; ++step)                  //枚举16次翻转
  {
    DFS(1,1,0);                                  //从(1,1)开始，当前步数为0
    if(flag)                                     //如果找到方案，结束枚举
      break;
  }
  flag?printf("%d\n",step):puts("Impossible");
  return 0;
}

