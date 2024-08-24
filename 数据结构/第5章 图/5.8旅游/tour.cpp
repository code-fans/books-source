//旅游
#include <bits/stdc++.h>
using namespace std;
const long long INF=1<<30;

long long n,m;
long long dis[105][105],g[105][105];

void Floyd()
{
  long long ans=INF;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        if(j!=i&&k!=i&&j!=k)
          ans=min(ans,dis[j][k]+g[j][i]+g[i][k]);     //注意要先求最小环
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]); //再更新dis[j][k]
  }
  if(ans==INF)
    puts("It's impossible.");
  else
    printf("%lld\n",ans);
}

int main()
{
  freopen("tour.in","r",stdin);
  freopen("tour.out","w",stdout);
  long long u,v,w;
  while(~scanf("%lld%lld",&n,&m))
  {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        dis[i][j]=g[i][j]=INF;
    for(int i=0; i<m; i++)
    {
      scanf("%lld%lld%lld",&u,&v,&w);
      dis[u][v]=min(dis[u][v],w);                      //注意重边
      dis[v][u]=dis[u][v];
      g[u][v]=g[v][u]=dis[u][v];
    }
    Floyd();
  }
  return 0;
}

