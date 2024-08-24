//引水入城—DFS+区间选点
//区域一定是连续的区间，因为区间中如果有城市是由别的水引进来的话，
//那么两水间一定有交叉点,那从这交叉点就可以到达
//因为DFS深度太大，Windows下有一组数据会崩溃
#include<bits/stdc++.h>
using namespace std;
int h[505][505],l[505][505],r[505][505];
int N,M,sum;
bool vis[505][505];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

void DFS(int x,int y)
{
  vis[x][y]=true;
  for (int i=0; i<4; i++)
  {
    int X=x+dx[i];
    int Y=y+dy[i];
    if (X<1 || X>N || Y<1 || Y>M || h[x][y]<=h[X][Y])//如果不用continue
      continue;                                      //必须前面加返回条件
    if (!vis[X][Y])
      DFS(X,Y);
    l[x][y] = min(l[x][y], l[X][Y]);//无论前面有没有DFS，最后值是一定要更新的
    r[x][y] = max(r[x][y], r[X][Y]);//所以如果没有DFS直接跳出，就无法更新
  }
}

int main()
{
  //freopen("flow.in","r",stdin);
  //freopen("flow.out","w",stdout);
  memset(l,127,sizeof(l));
  scanf("%d%d",&N,&M);
  for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
      scanf("%d",&h[i][j]);     //读取所有城市的海拔
  for (int i=1; i<=M; i++)
    l[N][i]=r[N][i]=i;          //第N行城市左右边界初始化
  for (int i=1; i<=M; i++)
    if(h[1][i]>=h[1][i+1] && h[1][i]>=h[1][i-1] && !vis[1][i])//优化
      DFS(1,i);                 //比左右都高才选，否则必有点比它覆盖范围更广
  for (int i=1; i<=M; i++)      //统计是否有区域无法覆盖
    if (!vis[N][i])
      sum++;
  if (sum)
    printf("0\n%d\n",sum);
  else
  {
    for(int L=1, R=r[1][1]; L<=M; L=R+1)            //区间选点
    {
      for (int i=1; i<=M; i++)
        if (l[1][i]<=L)
          R=r[1][i];
      sum++;
    }
    printf("1\n%d\n",sum);
  }
  return 0;
}
