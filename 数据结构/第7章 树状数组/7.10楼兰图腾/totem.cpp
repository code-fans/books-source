#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define lowbit(a) ((a) & (-1 * (a)))

inline void read(long long &x)
{
  x = 0;
  char ch = getchar(), c = ch;
  while(ch < '0' || ch > '9')c = ch, ch = getchar();
  while(ch <= '9' && ch >= '0')x = x * 10 + ch - '0', ch = getchar();
  if(c == '-')x = -x;
}

const long long MAXN = 1000000 + 10;

long long n, num[MAXN], bst[MAXN],ma;
int tmp1[MAXN], tmp2[MAXN];

void modify(long long p, long long k)
{
  for(; p <= ma; p += lowbit(p))bst[p] += k;
}

long long ask(long long p)
{
  long long sum = 0;
  for(; p; p -= lowbit(p))sum += bst[p];
  return sum;
}

int main()
{
  freopen("totem.in","r",stdin);
  freopen("totem.out","w",stdout);
  read(n);
  for(register long long i = 1; i <= n; ++ i) read(num[i]), ma = max(ma, num[i]);
  register long long ans = 0;
  for(register long long i = 1; i <= n; ++ i)
  {
    if(num[i] < 0 || num[i] > n)continue;
    tmp1[i] = ask(n - num[i]);
    modify(n - num[i] + 1, 1);
  }
  memset(bst, 0, sizeof(bst));
  for(register long long i = n; i >= 1; -- i)
  {
    if(num[i] < 0 || num[i] > n)continue;
    tmp2[i] = ask(n - num[i]);
    modify(n - num[i] + 1, 1);
  }
  for(register long long i = 1; i <= n; ++ i)ans += tmp1[i] * tmp2[i];
  printf("%lld ", ans);
  ans = 0;
  memset(bst, 0, sizeof(bst));
  for(register long long i = 1; i <= n; ++ i)
  {
    if(num[i] < 0 || num[i] > n)continue;
    tmp1[i] = ask(num[i] - 1);
    modify(num[i], 1);
  }
  memset(bst, 0, sizeof(bst));
  for(register long long i = n; i >= 1; -- i)
  {
    if(num[i] < 0 || num[i] > n)continue;
    tmp2[i] = ask(num[i] - 1);
    modify(num[i], 1);
  }
  for(register long long i = 1; i <= n; ++ i)ans += tmp1[i] * tmp2[i];
  printf("%lld\n", ans);
  return 0;
}

