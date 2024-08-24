//Ⱦɫ����-BFS�㷨
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10020;
vector<int>G[maxn];
int color[maxn];
int V,E;

int Bfs(int x)                              //�ǵݹ鷽ʽ��BFS
{
  queue<int>q;                              //BFS�ö������
  q.push(x);
  color[x] = 1;
  while (!q.empty())                        //�����в�Ϊ��
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
        return 0;                           //���Ƕ���ͼ���˳�����
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
    if(i==V)                                   //�Ӷ���1��ʼ
      cout << "Yes" << endl;
  }
  return 0;
}

