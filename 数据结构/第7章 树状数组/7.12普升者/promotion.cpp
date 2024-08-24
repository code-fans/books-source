#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
struct data
{
  int w , id;
} a[N];
int n , v[N] , pos[N] , f[N] , ans[N] , head[N] , to[N] , Next[N] , cnt;
void add(int x , int y)
{
  to[++cnt] = y , Next[cnt] = head[x] , head[x] = cnt;
}
bool cmp(data a , data b)
{
  return a.w < b.w;
}
void update(int x , int a)
{
  int i;
  for(i = x ; i <= n ; i += i & -i) f[i] += a;
}
int query(int x)
{
  int i , ans = 0;
  for(i = x ; i ; i -= i & -i) ans += f[i];
  return ans;
}
void dfs(int x)
{
  int i;
  ans[x] -= query(v[x]);
  for(i = head[x] ; i ; i = Next[i]) dfs(to[i]);
  ans[x] += query(v[x]);
  update(v[x] , 1);
}
int main()
{
  //freopen("promotion4.in","r",stdin);
  //freopen("promotion4.ans","w",stdout);
  int i , x;
  scanf("%d" , &n);
  for(i = 1 ; i <= n ; i ++ ) scanf("%d" , &a[i].w) , a[i].id = i;
  sort(a + 1 , a + n + 1 , cmp);
  for(i = 1 ; i <= n ; i ++ ) v[a[i].id] = n - i + 1;
  for(i = 2 ; i <= n ; i ++ ) scanf("%d" , &x) , add(x , i);
  dfs(1);
  for(i = 1 ; i <= n ; i ++ ) printf("%d\n" , ans[i]);
  return 0;
}
