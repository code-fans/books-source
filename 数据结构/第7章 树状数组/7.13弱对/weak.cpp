#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
const int N = 2e5 + 7;
const ll inf = LONG_MAX;
using namespace std;
struct edge
{
  int e,nxt;
} E[N];
int h[N], cc;
void adde(int u,int v)
{
  E[cc].e=v;
  E[cc].nxt=h[u];
  h[u]=cc;
  ++cc;
}
int n, rt, in[N];
ll k, a[N];
vector<ll> v;
int num;
ll B[N], num0 , ans = 0;
int id(ll x)
{
  return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
void add(int x,ll v)
{
  for(int i=x; i<=num; i+=(i&(-i))) B[i]+=v;
}
ll ask(int x)
{
  ll ans = 0;
  for(int i=x; i; i-=(i&(-i))) ans+=B[i];
  return ans;
}
void dfs(int u)
{
  for(int i=h[u]; ~i; i=E[i].nxt)
  {
    int v = E[i].e;
    if(a[v]) ans += ask(id(k/a[v]));
    else ans += ask(id(inf));
    add(id(a[v]),1LL);
    dfs(v);
    add(id(a[v]),-1LL);
  }
}
void dfs2(int u,ll dep,ll num0)
{
  for(int i=h[u]; ~i; i=E[i].nxt)
  {
    int v = E[i].e;
    if(a[v] == 0) ans += dep;
    else ans += num0;
    dfs2(v,dep+1,num0+(a[v]==0));
  }
}
int T;
int main()
{
  freopen("weak1.in","r",stdin);
  freopen("weak1.ans","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%lld",&n,&k);
    v.clear();
    cc = 0;
    for(int i = 1; i <= n; ++i)
    {
      scanf("%lld",&a[i]);
      if(a[i]) v.pb(a[i]), v.pb(k/a[i]);
      else v.pb(0), v.pb(inf);
      h[i] = -1;
      in[i] = 0;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    num = v.size();
    for(int i = 1; i < n; ++i)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      adde(u,v);
      ++in[v];
    }
    for(int i = 1; i <= n; ++i) if(!in[i])
      {
        rt = i;
        break;
      }
    ans = 0;

    if(k == 0)
    {
      dfs2(rt,1,(a[rt]==0));
    }
    else
    {
      add(id(a[rt]),1LL);
      dfs(rt);
      add(id(a[rt]),-1LL);
    }
    printf("%lld\n",ans);
  }
}
