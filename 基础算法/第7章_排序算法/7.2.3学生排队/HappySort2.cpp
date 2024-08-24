//树状数组解决学生排队
#include<bits/stdc++.h>
using namespace std;
#define MAXV 1000010
#define MAXN 100010
typedef long long LL;
LL n, a[MAXN], cnt[MAXN], bits[MAXV], maxv;

template<class T> inline void read(T& x)
{
  char t;
  bool sign = false;
  while((t = getchar()) != '-' && (t < '0' || t > '9'));
  if(t == '-')sign = true, t = getchar();
  x = t - '0';
  while((t = getchar()) >= '0' && t <= '9')x = x * 10 + t - '0';
  if(sign)x = -x;
}

LL sum(int x)
{
  LL res = 0;
  for(int i = x; i > 0; i -= i & -i)res += bits[i];
  return res;
}

void add(LL x, LL val)
{
  for(; x <= maxv; x += x & -x)bits[x] += val;
}

int main()
{
  //freopen("HappySort.in","r",stdin);
  //freopen("HappySort.out","w",stdout);
  while(~scanf("%I64d", &n))
  {
    memset(cnt, 0, sizeof(cnt));
    maxv = 0;
    for(int i = 1; i <= n; ++i)
    {
      read(a[i]);
      ++a[i];
      if(a[i] > maxv)maxv = a[i];
    }

    memset(bits, 0, sizeof(bits));
    for(int i = 1; i <= n; ++i)
    {
      cnt[i] += (i - 1) - sum(a[i]);
      add(a[i], 1);
    }

    memset(bits, 0, sizeof(bits));
    for(int i = n; i > 0; --i)
    {
      cnt[i] += sum(a[i] - 1);
      add(a[i], 1);
    }

    LL ans = 0;
    for(int i = 1; i <= n; ++i)ans += (1LL + cnt[i]) * cnt[i] / 2LL;
    printf("%I64d\n", ans);
  }
  return 0;
}
