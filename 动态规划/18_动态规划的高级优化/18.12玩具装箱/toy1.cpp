//Íæ¾ß×°Ïä
#include <bits/stdc++.h>
using namespace std;
#define S(x) 1ll * (x) * (x)
#define A(i) (sum[i] + (i))
#define B(i) (sum[i] + (i) + L + 1)

int n, L, l, r, sum[500010], Queue[500010];
long long Dp[500010];

double slope(int x, int y)
{
  return 1.0*(Dp[x]+S(B(x))-Dp[y]-S(B(y)))/(B(x)-B(y));
}

int main()
{
  //freopen("toy10.in","r",stdin);
  //freopen("toy10.ans","w",stdout);

  scanf("%d%d", &n, &L);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d",&sum[i]);
    sum[i]+=sum[i-1];
  }
  for (int i = 1; i <= n; i++)
  {
    while (l<r && slope(Queue[l+1], Queue[l]) <= 2*A(i))
      l++;
    Dp[i] = Dp[Queue[l]] + S(A(i) - B(Queue[l]));
    while (l < r && slope(Queue[r], Queue[r - 1]) > slope(i, Queue[r]))
      r--;
    Queue[++r] = i;
  }
  printf("%lld", Dp[n]);
  return 0;
}

