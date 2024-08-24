//ÆïÊ¿±éÀú2
#include<bits/stdc++.h>
using namespace std;

int n,Count;
int dx[8]= {-1,-2,-2,-1, 1, 2,2,1};
int dy[8]= { 2, 1,-1,-2,-2,-1,1,2};
int Map[41][41];

int DFS(int x,int y,int step)
{
  if(step>Count)
    return 1;
  else if( x<1 || x>n || y>n || y<1 || Map[x][y])
    return 0;
  else
  {
    Map[x][y]=step;
    for(int k=0; k<8; k++)
      if(DFS(x+dx[k],y+dy[k],step+1))
        return 1;
    Map[x][y]=0;
    return 0;
  }
}

int main()
{
  freopen("knight2.in","r",stdin);
  freopen("knight2.out","w",stdout);
  int x,y;
  cin>>n>>x>>y;
  Count=n*n;
  if(DFS(x,y,1))
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        cout<<Map[i][j]<<(j==n?'\n':' ');
  else
    puts("-1");
  return 0;
}
