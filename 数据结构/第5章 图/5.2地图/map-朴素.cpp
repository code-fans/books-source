//Dijkstra算法
#include <bits/stdc++.h>
using namespace std;
const int Max=1<<30;
const int MAXN=1510;

int n;
int Map[MAXN][MAXN];                     //存储图
int visit[MAXN];                         //设置访问标记
int d[MAXN];                             //起点到各结点的最小距离

void Dijkstra(int x)                     //求从起x点到其它结点的单源最短路径
{
  int Min,p;
  for(int i=1; i<=n; i++)                //预处理出从起始点x到各结点的最短距离
    d[i]=Map[x][i];
  visit[x]=1;                            //设起点为已访问过
  d[x]=0;                                //自身到自身为零
  for(int i=1; i<n; i++)
  {
    Min=Max;                             //最短路径初始设为无穷大
    for(int j=1; j<=n; j++)
      if(!visit[j] && Min>d[j])          //找没查找过的路径最短的结点
      {
        p=j;                             //定位路径最短的结点
        Min=d[j];
      }
    visit[p]=1;                          //路径最短结点设为已访问
    for(int j=1; j<=n; j++)              //更新未查找结点的最小距离总和
      if(!visit[j] && Min+Map[p][j]<d[j])//Min为Map[x][p]+Map[p][j]
        d[j]=Min+Map[p][j];
  }
  for(int i=1; i<=n; i++)                //打印出从起点x到任意点的最短距离
    cout<<d[i]<<'\n';
}

int main()
{
  //freopen("map.in","r",stdin);
  //freopen("map.out","w",stdout);
  cin>>n;                                //n个结点
  for(int i=1; i<=n; i++)                //读入图
    for(int j=1; j<=n; j++)
    {
      cin>>Map[i][j];
      if(Map[i][j]==-1)                  //若不存在路径,则为+∞,计算时小心溢出
        Map[i][j]=Max;
    }
  Dijkstra(1);
  return 0;
}

