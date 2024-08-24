//奖励
#include <bits/stdc++.h>
using namespace std;

int in[10005];
int bonus[10005];
vector<int> g[10005];

int main()
{
  freopen("bonus.in","r",stdin);
  freopen("bonus.out","w",stdout);
  int n,m;
  while(cin >> n >> m && n != 0)
  {
    for(int i = 0; i < n; i++)
      g[i].clear();
    memset(in,0,sizeof(in));
    memset(bonus,0,sizeof(bonus));

    for(int i = 0; i < m; i++)
    {
      int x,y;
      cin >> x >> y;
      g[y].push_back(x);
      in[x]++;//此处是x入度+1,因为先选最低资金的
    }

    queue<int> q;
    int count = 0;
    for(int i = 1; i <= n; i++)
      if(in[i] == 0)           //最低奖金的
      {
        bonus[i] = 100;
        q.push(i);
        count++;
      }

    while(!q.empty())
    {
      int temp = q.front();
      q.pop();
      for(int i = 0; i < g[temp].size(); i++)
      {
        bonus[g[temp][i]] = bonus[temp] + 1;//比他大的都加1
        in[g[temp][i]]--;
        if(in[g[temp][i]] == 0)
        {
          q.push(g[temp][i]);
          count++;
        }
      }
    }
    if(count == n)
    {
      int add = 0;
      for(int i = 1; i <= n; i++)
        add += bonus[i];
      cout << add << endl;
    }
    else
      cout << "-1" << endl;
  }
  return 0;
}

