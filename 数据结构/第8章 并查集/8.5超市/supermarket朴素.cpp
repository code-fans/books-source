#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int N = 1e5 + 5;
int vis[N];
struct node
{
  int p, d;
} a[N];

bool cmp(node x, node y)
{
  return x.p > y.p;
}

int main()
{
  //freopen("supermarket.in","r",stdin);
  //freopen("supermarket.out","w",stdout);

  int n;
  while(cin >> n)
  {
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++)
      scanf("%d%d", &a[i].p, &a[i].d);
    ll ans = 0;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
      for (int j = a[i].d; j >= 1; j--)  // 遍历天数
        if (vis[j] == 0)
        {
          ans += a[i].p;
          vis[j] = 1; // 标记
          break;
        }
    cout << ans << "\n";
  }
  return 0;
}
