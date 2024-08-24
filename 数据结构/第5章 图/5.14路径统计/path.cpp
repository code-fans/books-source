//路径统计-Dijkstra
#include<bits/stdc++.h>
using namespace std;

const int N=2010;
int edg[N][N],dis[N],cnt[N];     //cnt[i]:从1到i的最短路径方案数
bool visit[N];

int main()
{
  freopen("path.in","r",stdin);
  freopen("path.out","w",stdout);
  int n,m,x,y,z;
  scanf("%d%d", &n,&m);
  memset(edg,127,sizeof(edg));
  memset(dis,127,sizeof(dis));
  for(int i = 1; i <= m; i++)
  {
    scanf("%d%d%d", &x, &y, &z);
    edg[x][y]=min(edg[x][y], z); //处理重边
  }
  dis[1]=0;                      //从1到1的最短距离为0
  cnt[1]=1;
  for(int i=1; i<n; i++)
  {
    int MIN=0x7f7f7f,least;
    for(int j=1; j<=n; j++)
      if(dis[j]<MIN && !visit[j])//找出没有标记的最短边
        MIN=dis[j], least=j;
    visit[least]=1;
    for(int j=1; j<=n; j++)
      if(!visit[j] && dis[least]+edg[least][j]<dis[j])
      {
        dis[j]=dis[least]+edg[least][j];//到某点的最短路长度被更新
        cnt[j]=cnt[least];//它的最短路径数等于更新它的点的最短路径数
      }
      else if(dis[least]+edg[least][j]==dis[j])//否则若与最短路长度相等
        cnt[j]+=cnt[least];//就把更新的点的最短路径数加上（加法原理）
  }
  dis[n]>=0x7f7f7f?cout<<"No answer\n":cout<<dis[n]<<' '<<cnt[n]<<endl;
  return 0;
}

