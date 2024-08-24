//唯一最短路 —次小生成树2
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=105;

bool Tlink[MAXN][MAXN],vis[MAXN];//Tlink记录边是否在MST中,vis[i]:i点是否在MST
int w[MAXN][MAXN];               //w[i][j]为i到j的边的权值
int lowc[MAXN], pre[MAXN];
int Max[MAXN][MAXN];             //Max[i,j]为MST中连结i,j唯一路中最大边权值
int n, m;

int Prim()
{
  int p;
  int minc, res = 0;
  memset( vis, false, sizeof(vis));
  memset( pre, 0, sizeof(pre));
  memset( Max, 0, sizeof(Max));
  vis[1] = 1;                    //从第一个结点开始
  pre[1] = 1;                    //前驱是结点１
  for(int i = 2; i <= n; i ++)   //初始化
  {
    lowc[i] = w[1][i];
    pre[i] = 1;
  }

  for(int i = 2; i <= n; i ++)   //Prim算法
  {
    minc = INF;
    p = -1;
    for(int j = 1; j <= n; j ++)
    {
      if( !vis[j] && lowc[j] < minc)//找出结点没有被加入MST的最小权值边
      {
        minc = lowc[j];
        p = j;
      }
    }
    vis[p] = true;               //该结点加入MST
    res += minc;                 //最小树权值累加
    Max[ pre[p] ][p] = minc;
    Tlink[ pre[p] ][p] = true;   //将这条边标记为最小树的边
    Tlink[p][ pre[p] ] = true;   //将这条边标记为最小树的边
    for(int k = 1; k <= n; k ++)
      Max[k][p] = max( Max[ pre[p] ][p], Max[k][p]);//更新连接该边的最大值
    for(int j = 1; j <= n; j ++)              //更新p点到j点的最小边权值
      if( !vis[j] && lowc[j] > w[p][j])
      {
        lowc[j] = w[p][j];
        pre[j] = p;              //确定前驱结点
      }
  }
  return res;
}

int main()
{
  //freopen("OnePath.in","r",stdin);
  //freopen("OnePath.out","w",stdout);
  int s, e, t, Ans, ans;
  cin>>n>>m;
  memset(w,63,sizeof(w));//设为无穷大,63=127/2
  memset( Tlink, false, sizeof Tlink);
  for( int i = 1; i <= m; i ++)
  {
    cin>>s>>e>>t;
    w[s][e] = t;         //读入邻接表 
    w[e][s] = t;
  }
  Ans = Prim();                  //Prim算法求出最小生成树权值
  for( int i = 1; i <= n; i ++)
  {
    for( int j = 1; j <= n; j ++)
    {
      if( w[i][j] == INF || Tlink[i][j])//如果该点在最小生成树或者无边则忽略
        continue;
      ans = Ans + w[i][j] - Max[i][j];//Max[i,j]:MST中连结i,j中最大边权值
      if( Ans == ans)    //如果发现加非最小树的一条边后权值与原最小树权值相等
      {
        printf( "Not Unique!\n");
        exit(0);
      }
    }
  }
  printf( "%d\n", Ans);
  return 0;
}

