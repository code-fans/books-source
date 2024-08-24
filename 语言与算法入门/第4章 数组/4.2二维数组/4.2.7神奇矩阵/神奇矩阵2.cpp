//神奇矩阵
#include <bits/stdc++.h>
using namespace std;
int a[3][3],b[3][3];

int main()
{
  int i,tx,ty;
  int x=0,y=1;
  a[0][1]=1;//填入1
  for(i=2; i<=9; i++) //依次填入2~9
  {
    tx=(x+2)%3;
    ty=(y+1)%3;
    if(a[tx][ty]==0)//如果当前位置为空
    {
      a[tx][ty]=i;//填数
      x=tx;
      y=ty;
    }
    else
    {
      x=(x+1)%3;
      a[x][y]=i;
    }
  }
  for(i=0; i<=3; i++)
  {
    printf("%d%d%d\n",a[0][0],a[0][1],a[0][2]);
    printf("%d%d%d\n",a[1][0],a[1][1],a[1][2]);
    printf("%d%d%d\n",a[2][0],a[2][1],a[2][2]);
    printf("\n");
    printf("%d%d%d\n",a[2][0],a[2][1],a[2][2]); //上下翻转
    printf("%d%d%d\n",a[1][0],a[1][1],a[1][2]);
    printf("%d%d%d\n",a[0][0],a[0][1],a[0][2]);
    printf("\n");

    for(int ii=0; ii<3; ii++) //翻转到辅助数组
      for(int jj=0; jj<3; jj++)
        b[jj][2-ii]=a[ii][jj];
    for(int ii=0; ii<3; ii++)
      for(int jj=0; jj<3; jj++)
        a[ii][jj]=b[ii][jj];
  }
  return 0;
}

