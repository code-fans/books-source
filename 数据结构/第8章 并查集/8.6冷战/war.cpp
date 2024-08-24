#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500001;

int N,M,opt,x,y,lastans;
int fa[MAXN], deep[MAXN], mx[MAXN],siz[MAXN];

int Find(int x)//不能路径压缩（我们要用到树上路径）
{
  if(x == fa[x])
    return x;
  else
  {
    int f = Find(fa[x]);       //要先保存一下
    deep[x] = deep[fa[x]] + 1;
    return f;
  }
}

void Union(int x, int y, int tim)
{
  int fx = Find(x), fy = Find(y);
  if(fx == fy)
    return;
  if(siz[fx] > siz[fy])//秩
    swap(fx, fy);
  fa[fx] = fy;        //靠高度大的 即按树高合并，这样树高只有logn
  siz[fy] += siz[fx];
  mx[fx] = tim;       //修建时间戳
}

int Query(int x, int y)
{
  int ans = 0;
  while(x != y)
  {
    if(deep[x] < deep[y])
      swap(x, y);
    ans = max(ans, mx[x]);//求路径上的最大时间戳
    x = fa[x];
  }
  return ans;
}

int main()
{
  //freopen("war.in","r",stdin);
  //freopen("war.out","w",stdout);
  cin>>N>>M;
  for(int i = 1; i <= N; i++)
    fa[i] = i, siz[i] = 1;
  int tim = 0;
  for(int i = 1; i <= M; i++)
  {
    cin>>opt>>x>>y;
    x^=lastans, y^=lastans;
    if(opt)
      printf("%d\n",lastans=Find(x)^Find(y) ? 0:Query(x, y));
    else
      Union(x, y, ++tim);
  }
  return 0;
}
