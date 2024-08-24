//∑¢œ÷ª∑
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
int father[maxn], vis[maxn], ans[maxn];
vector<int> edge[maxn];
int n, s, f;

int findRoot(int x)
{
  return father[x] == x ? x : father[x] = findRoot(father[x]);
}

void DFS(int u, int index)
{
  ans[index] = u;
  if(u == f)
  {
    sort(ans, ans+ index + 1);
    for(int i = 0; i <= index; i++)
      printf("%d%c", ans[i], i==index?'\n':' ');
    return;
  }
  vis[u] = 1;
  for(int i = 0; i < edge[u].size(); i++)
  {
    int v = edge[u][i];
    if(!vis[v])
      DFS(v, index+1);
  }
  vis[u] = 0;
}

int main()
{
  while(scanf("%d", &n) == 1)
  {
    int u, v;
    for(int i = 1; i <= n; i++)
      father[i] = i;
    for(int i = 0; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      int ru = findRoot(u);
      int rv = findRoot(v);
      if(ru == rv)
        s = u, f = v;
      else
      {
        father[ru] = rv;
        edge[u].push_back(v);
        edge[v].push_back(u);
      }
    }
    memset(vis, 0, sizeof(vis));
    DFS(s, 0);
  }
  return 0;
}
