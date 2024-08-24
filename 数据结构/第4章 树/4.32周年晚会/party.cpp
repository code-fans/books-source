#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
vector<int> edge[maxn];
map<string,int> mp;
int n,f[maxn][2],ans,v[maxn],cnt;

void Dfs(int now,int fa)
{
  f[now][1]=v[now];
  for(int to:edge[now])
  {
    if(to==fa)
      continue;
    Dfs(to,now);
    f[now][1]+=f[to][0];
    f[now][0]+=max(f[to][1],f[to][0]);
  }
}

int main()
{
//  //freopen("party.in","r",stdin);
//  //freopen("party.out","w",stdout);
  cin>>n;
  int rt=1;
  for(int i=1; i<=n; i++)
  {
    string a,b;
    int c;
    cin>>a>>c>>b;
    if(mp[a]==0)
      mp[a]=++cnt;
    if(mp[b]==0)
      mp[b]=++cnt;
    if(rt==mp[a])
      rt=mp[b];
    v[mp[a]]=c;
    edge[mp[a]].push_back(mp[b]);
    edge[mp[b]].push_back(mp[a]);
  }
  Dfs(rt,0);
  cout<<max(f[rt][0],f[rt][1])<<endl;
  return 0;
}
