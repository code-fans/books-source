//骑士遍历1 - 简单样例代码
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("knight.in","r",stdin);
  freopen("knight.out","w",stdout);
  int k=0,num=0,x=1,y=1,X,Y;               //num为步数，A点从x=1,y=1开始
  int step[1000];                        //存储每走一步的方向
  int dx[5]= {0, 1, 2,2,1};            //控制x方向的增量数组
  int dy[5]= {0,-2,-1,1,2};            //控制y方向的增量数组
  cin>>X>>Y;
  while(1)
  {
    if(x==X && y==Y)                   //如果到达Ｂ点，则退出
      break;
    k++;                               //改变方向
    if(k>4)                            //如果4个方向都试完了，后退一步
    {
      k=step[num];                     //获得方向
      num--;                           //步数减1
      if(num==0)
      {
        cout<<-1<<endl;
        return 0;
      }
      x-=dx[k];                        //复原x
      y-=dy[k];                        //复原y
    }
    else                               //否则试着按k的方向前进
    {
      x+=dx[k];
      y+=dy[k];
      if(x>X||x<1||y>Y||y<1||(Y-y)>(2*(X-x)))         //如果试的方向超出棋盘范围，则退回
      {
        x-=dx[k];
        y-=dy[k];
      }
      else                             //如果该方向可以走
      {
        num++;                         //步数加1
        step[num]=k;                   //将该步方向存入数组
        k=0;                           //将下一步的方向初始为0
      }
    }
  }
  for(k=1; k<=num; k++)
    printf("%d ",step[k]);
  return 0;
}

