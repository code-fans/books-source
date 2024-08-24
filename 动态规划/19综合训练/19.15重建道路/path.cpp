#include<bits/stdc++.h>
using namespace std;
const int N=310;

inline int read()                        //以字符串形式读入数字可提速
{
  int x=0;
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //位运算优化即x*8+x*2=x*10
  return x;
}


struct node
{
  int u, v, next;
} edge[N];

int n, p;
int cnt, head[N];
int f[N][N];
int a[N];
bool b[N];
int root;
int ans = 0x3f3f3f3f;

inline void add (int u, int v)
{
  edge[++cnt].v = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
}

inline int dfs (int now)
{
  int temp;
  int sum = 1;
  for (int i = head[now]; i; i = edge[i].next)
  {
    int v = edge[i].v;
    temp = dfs (v);
    sum += temp;
    for (int j = sum; j >= 1; j --)
      for (int k = 1; k < j; k ++)
        f[now][j] = min (f[now][j], f[now][j - k] + f[v][k] - 1);
  }
  return sum;
}

int main ()
{
  n = read ();
  p = read ();
  int x, y;
  for (int i = 1; i <= n - 1; i ++)
  {
    x = read ();
    y = read ();
    a[x] ++;
    b[y] = 1;
    add (x, y);
  }
  memset (f, 0x3f3f3f3f, sizeof (f));
  for (int i = 1; i <= n; i ++)
  {
    if (!b[i]) root = i;
    f[i][1] = a[i];
  }
  dfs (root);
  ans = f[root][p];
  for (int i = 1; i <= n ; i ++)
  {
    if (f[i][p] < ans) ans = f[i][p] + 1;
  }
  printf ("%d", ans);
  return 0;
}
