//方格取数
#include <bits/stdc++.h>
using namespace std;

int a[11][11];                        //存放（x,y）的数字
int f1[101][101],f2[101][101];        //滚动数组存放i-1,i个阶段的状态
int x,y,z,n;

void Dp()
{
  for(int k=1; k<=2*n-1; k++)               //准备走第k步
  {
    for(int x1=1; x1<=k; x1++)       //枚举两条路径在第i-1步时的状态x1和x1
      for(int x2=x1; x2<=k; x2++)    //x2从x1开始，避免(x,y),(y,x)的重复计算
      {
        int Y1=k+1-x1;                       //如果定义y1，会有C++名称冲突
        int Y2=k+1-x2;                          //Y2=k+1-x2
        if(x1<=n && x1>=1 && x2<=n && x2>=1 && Y1>=1 && Y1<=n && Y2>=1 && Y2<=n)
          for(int DirA=0; DirA<=1; DirA++)        //A沿x方向走
            for(int DirB=0; DirB<=1; DirB++)      //B沿y方向走
            {
              int X=x1,Y=Y1,x=x2,y=Y2;
              if(DirA==0)                     //A向右走
                Y++;
              else                          //A向下走
                X++;
              if(DirB==0)                     //B向右走
                y++;
              else                          //B向下走
                x++;
              if(X<=n&&X>=1&&Y<=n&&Y>=1&&x<=n&&x>=1&&y>=1&&y<=n)
                f2[X][x]=max(f2[X][x],f1[x1][x2]+a[x][y]+(X==x?0:a[X][Y]));
            }
      }
    memcpy(f1,f2,sizeof(f2));               //复制滚动数组
  }
}

int main()
{
  freopen("GetNum.in","r",stdin);
  freopen("GetNum.out","w",stdout);
  cin>>n;
  n++;                               //给二维表多一行一列，保证起点无数据
  while(cin>>x>>y>>z,x && y && z)
    a[x+1][y+1]=z;                   //a数组存放方格数，对应行列坐标都加1
  Dp();
  cout<<f1[n][n]<<endl;
  return 0;
}

