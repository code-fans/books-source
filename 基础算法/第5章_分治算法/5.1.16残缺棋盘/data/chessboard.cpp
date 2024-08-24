//残缺棋盘
#include <bits/stdc++.h>
using namespace std;
int k=1,c[1024][1024];                  //左上角坐标设为(1，1)

void Lt(int x1,int y1,int x2,int y2 )   //左上
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=1;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=1;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=1;    //填充图形1
}

void Rt(int x1,int y1,int x2,int y2 )   //右上
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=2;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=2;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=2;  //填充图形2
}

void Lb(int x1,int y1,int x2,int y2 )   //左下
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=3;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=3;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=3;  //填充图形3
}

void Rb(int x1,int y1,int x2,int y2 )   //右下
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=4;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=4;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=4;    //填充图形4
}

void Out()                              //输出数组
{
  for(int i=1; i<=k; i++)
  {
    for(int j=1; j<=k; j++)
      cout<<c[i][j]<<' ';
    cout<<endl;
  }
}

void Work(int x1,int y1,int x2,int y2)  //递归函数
{
  int p,q;
  for(int i=x1; i<=x2; i++)             //查找该方块的坏点或已覆盖的点在何处
    for(int j=y1; j<=y2; j++)
      if(c[i][j]!=0)
        p=i,q=j;
  if(p<=(x1+(x2-x1)/2))
    if( q<=(y1+(y2-y1)/2))              //如该点位于左上角
      Rb(x1,y1,x2,y2);
    else                                //如该点在右上角
      Lb(x1,y1,x2,y2);
  if(p>(x1+(x2-x1)/2))
    if (q<=(y1+(y2-y1)/2))              //如该点位于左下角
      Rt(x1,y1,x2,y2);
    else                                //如该点在右下角
      Lt(x1,y1,x2,y2);
  if(x2-x1!=1)
  {
    Work(x1,y1,(x1+(x2-x1)/2),(y1+(y2-y1)/2));  //平分为四块后递归
    Work((x1+(x2-x1)/2+1),y1,x2,(y1+(y2-y1)/2));
    Work(x1,(y1+(y2-y1)/2+1),(x1+(x2-x1)/2),y2);
    Work((x1+(x2-x1)/2+1),(y1+(y2-y1)/2+1),x2,y2);
  }
}

int main()
{
  //freopen("chessboard.in","r",stdin);
  //freopen("chessboard.out","w",stdout);
  int n,x,y;
  cin>>n>>x>>y;
  for(int i=1; i<=n; i++)
    k*=2;
  c[x][y]=7;                            //定义坏的坐标为7
  Work(1,1,k,k);                        //左上坐标(1,1),右下坐标(k,k)
  Out();
  return 0;
}

