//过河卒
#include <bits/stdc++.h>
using namespace std;

long long F[100][100];
bool Map[100][100];
int dx[9]= {0,1,2,2,1,-1,-2,-2,-1};
int dy[9]= {0,2,1,-1,-2,-2,-1,1,2};

int main()
{
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  for(int i=0; i<9; i++)               //标记马的控制点
    if(x+dx[i]>=0 && x+dx[i]<=n && y+dy[i]>=0 && y+dy[i]<=m)
      Map[x+dx[i]][y+dy[i]]=true;
  for(int k=0; !Map[k][0] && k<=n; k++)//初始化第一列为1
    F[k][0]=1;
  for(int k=0; !Map[0][k] && k<=m; k++)//初始化第一行为1 
    F[0][k]=1;
  for(int i=1; i<=n; i++)              //从上到下 
    for(int j=1; j<=m; j++)            //从左到右 
      if(!Map[i][j])
        F[i][j]=F[i][j-1]+F[i-1][j];
  cout<<F[n][m]<<endl;
  return 0;
}
