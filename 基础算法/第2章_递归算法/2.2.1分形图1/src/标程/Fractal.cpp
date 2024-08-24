//分形图１
#include<bits/stdc++.h>
using namespace std;

char Map[731][731];

void Dg(int n,int x,int y)
{
  if(n==1)
  {
    Map[x][y]='X';
    return ;
  }
  int size=pow(3.0,n-2);
  Dg(n-1,x,y);                 //左上角
  Dg(n-1,x,y+2*size);          //右上角
  Dg(n-1,x+size,y+size);       //中间
  Dg(n-1,x+2*size,y);          //左下角
  Dg(n-1,x+2*size,y+2*size);   //右下角
}

int main()
{
  freopen("Fractal.in","r",stdin);
  freopen("Fractal.out","w",stdout);
  int i,j,n,size;
  while(scanf("%d",&n)!=EOF)
  {
    if(n==-1)
      break;
    size=pow(3.0,n-1);
    for(i=1; i<=size; i++)      //初始化
      for(j=1; j<=size; j++)
        Map[i][j]=' ';
    Dg(n,1,1);
    for(i=1; i<=size; i++)
    {
      for(j=1; j<=size; j++)
        printf("%c",Map[i][j]);
      printf("\n");
    }
    printf("-\n");
  }
  return 0;
}
