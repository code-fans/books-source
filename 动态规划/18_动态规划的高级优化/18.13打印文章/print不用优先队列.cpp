#include<cstdio>
typedef long long ll;
const int MAXN = 5e5+1e2;
struct Pos
{
  ll x, y;
  Pos(ll xx=0, ll yy=0)
    :x(xx), y(yy) {}
  Pos operator - (const Pos& b)
  {
    return Pos(x-b.x, y-b.y);
  }
} stk[MAXN];
int n, m, sz;
ll sum[MAXN], dp[MAXN];
ll cross(const Pos& a, const Pos& b)
{
  return a.x*b.y-a.y*b.x;
}
int main()
{
  //freopen("print15.in","r",stdin);
  //freopen("print15.ans","w",stdout);

  while(~scanf("%d%d", &n, &m))
  {
    for(int i=1; i<=n; ++i)
    {
      scanf("%I64d", sum+i);
      sum[i] += sum[i-1];
    }
    sz = 0;
    stk[sz++] = Pos(0,0);
    for(int i=1; i<=n; ++i)
    {
      int p = sz-1;
      while(p&&cross(stk[p]-stk[p-1], Pos(1,2*sum[i]))<=0)
        --p;
      dp[i] = stk[p].y+m+sum[i]*(sum[i]-2*stk[p].x);
      Pos now = Pos(sum[i], dp[i]+sum[i]*sum[i]);
      while(sz>1&&cross(stk[sz-1]-stk[sz-2], now-stk[sz-2])<=0)
        --sz;
      stk[sz++] = now;
    }
    printf("%I64d\n", dp[n]);
  }
  return 0;
}
