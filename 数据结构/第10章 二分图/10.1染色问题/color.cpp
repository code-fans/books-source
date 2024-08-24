//染色问题-BFS算法
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10020;
vector<int>G[maxn];
int color[maxn];
int V,E;

int Bfs(int x)                              //非递归方式的BFS
{
  queue<int>q;                              //BFS用队列完成
  q.push(x);
  color[x] = 1;
  while (!q.empty())                        //当队列不为空
  {
    int v = q.front();
    q.pop();
    for (int i = 0; i < G[v].size(); i++)
    {
      int u = G[v][i];
      if (color[u] == 0)
      {
        color[u] = -color[v];
        q.push(u);
      }
      else if (color[v] == color[u])
      {
        cout << "No" << endl;
        return 0;                           //不是二分图则退出程序
      }
    }
  }
  return 1;
}

int main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    memset(color,0,sizeof(color));
    for(int i=0; i<maxn; i++)
      G[i].clear();
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
      int s, t;
      cin >> s >> t;
      G[s].push_back(t);
      G[t].push_back(s);
    }
    int i=0;
    for(; i<V; i++)
    {
      if(Bfs(i)==0)
        break;
    }
    if(i==V)                                   //从顶点1开始
      cout << "Yes" << endl;
  }
  return 0;
}

