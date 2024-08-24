//染色问题-DFS算法
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10020;
vector <int> G[MAXN];
int color[MAXN];
int V, E;

bool Dfs(int v, int c)
{
  color[v] = c;                               //顶点染成c
  for (int i = 0; i < G[v].size(); i++)
  {
    if(color[G[v][i]]==c)                     //如果相邻点同色则返回false
      return false;
    if(color[G[v][i]]==0 && !Dfs(G[v][i],-c)) //如相邻点没染色，并且染-c失败
      return false;
  }
  return true;                                //如果均染色，就返回true
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
    for(int i=0; i<MAXN; i++)
      G[i].clear();
    cin>>V>>E;                                  //输入结点数和边数
    for (int i = 0; i < E; i++)
    {
      int s, t;
      cin >> s >> t;
      G[s].push_back(t);
      G[t].push_back(s);                        //有向图可省略此句
    }
    int flag=0;
    for (int i = 0; i < V; i++)
      if (color[i] == 0)
        if (!Dfs(i, 1))                         //如果染色失败
        {
          flag=1;
          cout << "No" << endl;
          break;
        }
    if(flag==0)
      cout << "Yes" << endl;
  }
  return 0;
}

