//骑士遍历2—Warnsdoff算法,部分数据找不到解，可再优化
#include <bits/stdc++.h>
using namespace std;

int N;
int dx[]= {2,1,-1,-2,-2,-1, 1, 2};
int dy[]= {1,2, 2, 1,-1,-2,-2,-1};
int board[100][100];

int ExitN(int x,int y,int start,int a[])//统计（x,y）的出口数
{
  int xx,yy,count=0;
  for(int k=0; k<8; k++)
  {
    xx=x+dx[(start+k)%8];//求出下一个点
    yy=y+dy[(start+k)%8];
    if(xx>=1 && xx<=N && yy>=1 && yy<=N && board[xx][yy]==0)
      a[count++]=(start+k)%8;//将出口的偏移下标值依次存到a数组
  }
  return count;//返回出口个数
}

int Next(int x,int y,int start)//返回出口最少的点
{
  int pos,a[8],b[8];
  int num=ExitN(x,y,start,a);//获取有多少个点可以走
  if(num==0)
    return -1;               //如果没有可以走的点，返回-1
  for(int min=N+1,k=0; k<num; k++) //找出口最少的点
  {
    int temp=ExitN(x+dx[a[k]],y+dy[a[k]],start,b);
    if(temp<min)
    {
      min=temp;
      pos=a[k];
    }
  }
  return pos;
}

int main()
{
  //freopen("knight2.in","r",stdin);
  //freopen("knight2.out","w",stdout);
  int x,y,step,start;
  cin>>N>>x>>y;
  board[x][y]=1;
  start=0;             //初始顺序是从偏移数组下标0开始
  do
  {
    for(step=2; step<=N*N; step++)
    {
      int pos=Next(x,y,start);
      if(pos==-1)      //找不到出口
        break;         //跳出循环，更改搜索顺序
      x+=dx[pos];      //更新当前点
      y+=dy[pos];
      board[x][y]=step;//在棋盘上记录步数
    }
    start++;           //换个顺序再找一遍，需要改进
  }
  while(step<N*N && start<8);
  if(step>N*N)
    for(int i=1; i<=N; i++)
      for(int j=1; j<=N; j++)
        printf("%d%c",board[i][j],(j==N?'\n':' '));
  else
    puts("-1");
  return 0;
}

