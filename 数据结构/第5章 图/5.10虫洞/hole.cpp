//虫洞
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int d[1005],v[2005],u[2005],w[2005];

bool bellman()
{
  for(int i = 1; i < 1005; i++)                 //d[0]=0
    d[i] = INF;
  for (int i = 0; i < n - 1; i++)               //松弛n-1次
    for (int j = 0; j < m; j++)                 //检查每条边
      if (d[v[j]] < INF)
        d[u[j]]=min(d[u[j]],d[v[j]]+w[j]);
  for (int i = 0; i < m; i++)                   //检查负边权
    if (d[v[i]]<INF && d[u[i]]>d[v[i]]+w[i])
      return true;
  return false;
}

int main()
{
  freopen("hole.in","r",stdin);
  freopen("hole.out","w",stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d%d%d", &v[i], &u[i], &w[i]);
  printf("%s\n", bellman()?"Possible":"Not possible");
  return 0;
}

