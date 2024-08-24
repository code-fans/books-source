//立体图
//从后往前，从上往下，从左往右依次覆盖
#include <bits/stdc++.h>
using namespace std;

int m,n,a[1001][1001],h;
int L[6]= {2,1,0,0,0,0};                  //每行左边起始位置
int R[6]= {6,6,6,6,5,4};                  //每行右边结束位置

char Map[1001][1001],Model[6][8] = {"  +---+",
                                    " /   /|",
                                    "+---+ |",
                                    "|   | +",
                                    "|   |/ ",
                                    "+---+  "
                                   };

void Block(int x,int y)
{
  for(int i=5; i>=0; i--)
    for(int j=L[i]; j<=R[i]; j++)         //从这一行的左边起始位置到右边结束位置
      Map[x+5-i][y+j]=Model[i][j];
}

int main()
{
  //freopen("drawing.in","r",stdin);
  //freopen("drawing.out","w",stdout);
  scanf("%d%d",&m,&n);
  for(int i=1; i<=m; i++)
    for(int j=0; j<n; j++)
    {
      scanf("%d",&a[i][j]);
      h=max(h,3*a[i][j]+3+(m-i)*2);        //h为立体图最大高度
    }
  for(int i=1; i<=m; i++)                  //从第一行到第m行
    for(int j=0; j<n; j++)                 //列
      for(int k=0; k<a[i][j]; k++)         //当前位置堆的积木个数
        Block(3*k+(m-i)*2+1,4*j+(m-i)*2+1);//从立方体左下角开始画
  for(int i=h,w=4*n+m*2+1; i>=1; i--)      //从上往下,w为立体图输出宽度
  {
    for(int j=1; j<=w; j++)                //从左往右输出
      printf("%c",Map[i][j]==NULL?'.':Map[i][j]);
    printf("\n");
  }
  return 0;
}
