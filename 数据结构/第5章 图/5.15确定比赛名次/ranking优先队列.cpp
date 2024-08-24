#include <bits/stdc++.h>
using namespace std;
const int MAXN=501;

bool w[MAXN][MAXN];
int ind[MAXN];

void TopoSort(int n)
{
  priority_queue<int,vector<int>,greater<int> > q;
  for(int j=1; j<=n; j++)
    if(ind[j]==0)
      q.push(j);
  for(int i=1; i<=n; i++)
  {
    int t=q.top();
    q.pop();
    cout<<t<<(i==n?'\n':' ');    //ÒÀ´ÎÊä³öÍØÆËÐò 
    for(int j=1; j<=n; j++)
      if(w[t][j])
      {
        ind[j]--;
        if(ind[j]==0)
          q.push(j);
      }
  }
}

int main()
{
  int n,m,a,b;
  while(cin>>n>>m)
  {
    memset(ind, 0, sizeof(ind));
    memset(w, false, sizeof(w));
    for (int i = 0; i < m; i++)
    {
      cin>>a>>b;
      if (!w[a][b])
        ind[b]++;
      w[a][b] = true;
    }
    TopoSort(n);
  }
  return 0;
}
