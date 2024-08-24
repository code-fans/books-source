//骑士遍历2 —回溯算法 
#include<bits/stdc++.h>
using namespace std;

int n,Count,x,y,k=2;
int Dx[9]= {0,-1,-2,-2,-1,1,2,2,1};
int Dy[9]= {0,2,1,-1,-2,-2,-1,1,2};
int Map[41][41];
int Dir[41];

bool Check(int x,int y)
{
  return (x>=1 && x<=n && y>=1 && y<=n);
}

int main()
{
  freopen("knight2.in","r",stdin);
  freopen("knight2.out","w",stdout);
  cin>>n>>x>>y;
  Count=n*n;
  Map[x][y]=1;
  while(k>1 && k<=Count)//调试可以输出x,y,k验证每一步的变化
  {
    Dir[k]++;
    if(Dir[k]>8)
    {
      Dir[k]=0;
      Map[x][y]=0;
      k--;
      x-=Dx[Dir[k]];
      y-=Dy[Dir[k]];
    }
    else
    {
      int xx=x+Dx[Dir[k]];
      int yy=y+Dy[Dir[k]];
      if(Check(xx,yy) && Map[xx][yy]==0)
      {
        x+=Dx[Dir[k]];
        y+=Dy[Dir[k]];
        Map[x][y]=k++;
      }
    }
  }
  if(k>Count)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        cout<<Map[i][j]<<(j==n?'\n':' ');
  else
    puts("-1");
  return 0;
}
