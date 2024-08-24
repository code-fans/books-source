#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> g[maxn];
int n;
bool vis[maxn], ok;
int dfs_clock, scc_cnt, belong[maxn], dfn[maxn], low[maxn], ans[maxn], cnt[maxn];
stack<int> s;

void tarjan(int u, int f)
{
  dfn[u] = low[u] = ++dfs_clock;
  s.push(u);
  for(int i = 0; i < g[u].size(); i++)
  {
    int v = g[u][i];
    if(v == f)                           //防止顺原路走回去
      continue;
    if(!dfn[v])
    {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    }
    else if(!belong[v])
      low[u] = min(low[u], dfn[v]);
  }
  if(low[u] == dfn[u])
  {
    scc_cnt++;
    while(1)
    {
      int x = s.top();
      s.pop();
      belong[x] = scc_cnt;
      if(x == u)
        break;
    }
  }
}

int main()
{
  while(cin >> n)
  {
    for(int i = 0; i < maxn; i++)
      g[i].clear();
    for(int i = 1; i <= n; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    memset(belong, 0, sizeof(belong));
    memset(dfn, 0, sizeof(dfn));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    while(!s.empty())
      s.pop();
    vis[1] = 1;
    dfs_clock = ok = 0;
    tarjan(1, 0);
    int index;
    for(int i = 1; i <= n; i++)
    {
      cnt[belong[i]]++;
      if(cnt[belong[i]] > 1)
        index = belong[i];
    }
    int num = 0;
    for(int i = 1; i <= n; i++)
    {
      if(belong[i] == index)
        ans[num++] = i;
    }
    sort(ans, ans+num);
    for(int i = 0; i < num; i++)
      printf("%d%c", ans[i], i==num-1 ? '\n' : ' ');
  }
  return 0;
}
