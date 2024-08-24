//胜利大逃亡
#include <bits/stdc++.h>
using namespace std;
const int dx[]= {-1,0,1,0};
const int dy[]= {0,-1,0,1};

bool bat[120][120][300];
int Map[120][120],f[120][120];

inline int Read(int x=0,char c=getchar())
{
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';
  return x;
}

int main()
{
  freopen("escape.in","r",stdin);
  freopen("escape.out","w",stdout);
  int m,n,p;
  cin>>m>>n>>p;
  int T=m+n-1;                           //走动次数
  for (int i=0; i<n+2; i++)              //围成一圈障碍
    Map[i][0]=Map[i][m+1]=2;
  for (int i=0; i<m+2; i++)
    Map[0][i]=Map[n+1][i]=2;

  for (int i=1; i<p+1; i++)              //读入石柱
  {
    int y=Read();
    int x=Read();
    Map[x][y]=1;                         //石柱为1
  }

  int b=Read();
  for (int j=1; j<b+1; j++)             //读入蝙蝠坐标
  {
    int y0=Read();
    int x0=Read();
    int d=Read()-1;
    int t=Read();
    int x=x0;
    int y=y0;
    if (x<1 || y<1 || x>n || y>m || Map[x][y]>0)
      continue;
    bat[x][y][1]=true;
    for (int i=1,tt; i<T; i++)//计算出蝙蝠动态位置
    {
      for (tt=0; tt<4 && Map[x+dx[d]][y+dy[d]]>0; ++tt)
        d=(d+t)%4;
      if (tt<4)
        x+=dx[d];
      bat[x][y+=dy[d]][i+1]=true;
    }
  }
  f[1][1]=1;
  for (int i=1; i<n+1; i++)
    for (int j=1; j<m+1; j++)
      if (!bat[i][j][i+j-1] && Map[i][j]==0 && f[i][j]==0)
        f[i][j]=f[i-1][j]+f[i][j-1];
  printf("%ld",f[n][m]);
  return 0;
}
