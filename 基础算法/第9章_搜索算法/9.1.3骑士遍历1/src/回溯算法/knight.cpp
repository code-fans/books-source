//骑士遍历1
#include <bits/stdc++.h>
using namespace std;

int k=0,m=0,X,Y,x=1,y=1;          //m为步数，A点从x=1,y=1开始
int step[1000];                   //存储每走一步的方向

int In(int x,int y)
{
  return (x>0 && x<=X && y>0 && y<=Y);
}

int main()
{
  //freopen("knight.in","r",stdin);
  //freopen("knight.out","w",stdout);
  cin>>X>>Y;
  int dx[5]= {0, 1, 2,2,1};       //控制x方向的增量数组
  int dy[5]= {0,-2,-1,1,2};       //控制y方向的增量数组
  while(x!=X || y!=Y)
  {
    k++;                          //改变方向
    if(k>4)                       //当4个方向都试完后，后退一步
    {
      k=step[m];                  //获得方向
      m--;                        //步数减1
      if(m<0)
      {
        puts("-1");
        exit(0);
      }
      x-=dx[k];                   //复原x
      y-=dy[k];                   //复原y
    }
    else                          //否则试着按k的方向前进
    {
      x+=dx[k];
      y+=dy[k];
      if(In(x,y))                 //如果试的方向在棋盘范围内
      {
        m++;                      //步数加1
        step[m]=k;                //将该步方向存入数组
        k=0;                      //将下一步的方向初始为0
      }
      else                        //如果该方向可以走
      {
        x-=dx[k];
        y-=dy[k];
      }
    }
  }
  for(k=1; k<m; k++)
    printf("%d ",step[k]);
  printf("%d\n",step[m]);
  return 0;
}

