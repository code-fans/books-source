#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define N 200005

using namespace std;

struct Node
{
  int x, id;
  friend bool operator < (Node aa, Node bb)
  {
    return aa.x > bb.x;
  }
} a[N];
struct Code
{
  int x, id;
} b[N];
priority_queue <Node> Q;
char str[10];
int ans, last, cnt, tot, n;

int main()
{
  freopen("dragons.in","r",stdin);
  freopen("dragons.out","w",stdout);

  scanf("%d", &n);
  last = 0;
  for (int i = 1; i <= n; i++)
  {
    scanf("%s", str);
    if (str[0] == 'c')
    {
      scanf("%d", &a[++cnt].x);
      a[cnt].id = i;
    }
    else
    {
      scanf("%d", &b[++tot].x);
      b[tot].id = i;
    }
  }
  int now = b[tot - 1].x;
  for (int i = tot - 2; i >= 1; i--)
    if (b[i].x > now) b[i].x = now;
    else now = min(now, b[i].x);
  int l1 = 1, l2 = 1;
  while (l1 <= cnt && l2 <= tot - 1)
  {
    while (l1 <= cnt && a[l1].id <= b[l2].id)
    {
      if (Q.size() < b[l2].x - 1) Q.push(a[l1]);
      else
      {
        if (Q.size() != 0)
          if (a[l1].x > Q.top().x)
          {
            Q.pop();
            Q.push(a[l1]);
          }
      }
      l1++;
    }
    l2++;
  }
  for (int i = l1; i <= cnt; i++) Q.push(a[i]);
  if (Q.size() < b[tot].x) printf("-1\n");
  else
  {
    int ans = 0;
    while (Q.size())
    {
      ans += Q.top().x;
      Q.pop();
    }
    printf("%d\n", ans);
  }
  return 0;
}
