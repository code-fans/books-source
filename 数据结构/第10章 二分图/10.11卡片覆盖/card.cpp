#include <bits/stdc++.h>
using namespace std;
const int N = 35* 35;
vector <int> G[N];
int match[N] , tx[] = {-1 , 0 , 1 , 0} , ty[] = {0 , 1 , 0 , -1} , n , m;
bool vis[N] , Map[35][35];

bool check(int x , int y)
{
  if(!Map[x][y] && x >= 0 && y >= 0 && x < n && y < m)
    return true;
  return false;
}

bool dfs(int u)
{
  for(int i = 0 ; i < G[u].size() ; ++i)
  {
    int v = G[u][i];
    if(!vis[v])
    {
      vis[v] = true;
      if(match[v] == -1 || dfs(match[v]))
      {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}

int hungry()
{
  int res = 0;
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      if((i + j) % 2 && !Map[i][j])
      {
        memset(vis , false , sizeof(vis));
        if(dfs(i*m + j))
          res++;
      }
  return res;
}

int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  int k , u , v;
  while(cin >> n >> m >> k)
  {
    memset(Map , false , sizeof(Map));
    memset(match , -1 , sizeof(match));
    for(int i = 0 ; i < n * m ; ++i)
      G[i].clear();
    for(int i = 0 ; i < k ; ++i)
    {
      cin >> u >> v;
      Map[--v][--u] = true;
    }
    for(int i = 0 ; i < n ; ++i)
      for(int j = 0 ; j < m ; ++j)
        if(!Map[i][j] && (i + j) % 2)
          for(int t = 0 ; t < 4 ; ++t)
          {
            int x = i + tx[t] , y = j + ty[t];
            if(check(x , y))
              G[i*m + j].push_back(x*m + y);
          }
    printf("%s\n" , 2*hungry() == n*m-k ? "YES" : "NO");
  }
  return 0;
}
