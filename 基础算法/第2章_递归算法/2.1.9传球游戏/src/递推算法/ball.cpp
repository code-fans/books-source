//传球游戏-递推算法
#include <iostream>
using namespace std;

int n,m;
int f[31][31];

int main()
{
  //freopen("ball.in","r",stdin);
  //freopen("ball.out","w",stdout);
  cin>>n>>m;
  f[1][0]=1;
  for(int j=1; j<=m; j++)
  {
    for(int i=2; i<=n-1; i++)
      f[i][j]=f[i-1][j-1]+f[i+1][j-1];
    f[1][j]=f[2][j-1]+f[n][j-1];
    f[n][j]=f[n-1][j-1]+f[1][j-1];
  }
  cout<<f[1][m]<<endl;
  return 0;
}
