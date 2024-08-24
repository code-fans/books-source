//Äæ×ªÎ´À´
#include<bits/stdc++.h>
using namespace std;

int f[205][205],n,m;
vector<int>e[205];
void dfs(int root)
{
  for(int i=0; i<e[root].size(); ++i)
  {
    int son=e[root][i];
    dfs(son);
    for(int j=m; j>1; --j)
      for(int k=0; k<j; ++k)
        f[root][j]=max(f[root][j],f[root][j-k]+f[son][k]);
  }
}
int main()
{
  //freopen("reverse.in","r",stdin);
  //freopen("reverse.out","w",stdout);

  while(scanf("%d%d",&n,&m)&&n+m)
  {
    ++m;
    memset(f,0,sizeof f);
    for(int i=0; i<=201; ++i)e[i].clear();
    for(int i=1; i<=n; ++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      e[x].push_back(i);
      for(int j=1; j<=m; ++j)
        f[i][j]=y;
    }
    dfs(0);
    printf("%d\n",f[0][m]);
  }
  return 0;
}
