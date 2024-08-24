//时空定位1
#include<bits/stdc++.h>
using namespace std;

double data[605];

int main()
{
  freopen("location.in", "r", stdin);
  freopen("location.out", "w", stdout);
  int N, n;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    double length = 0;
    scanf("%d", &n);
    for (int k = 1; k <= n; k++)
      scanf("%lf", &data[k]);
    sort(data + 1, data + 1 + n, greater<double>());
    for (int j = 1; j <= n; j++)
    {
      length += 2 * (sqrt(data[j] * data[j] - 1));     //覆盖的最大长度
      if (length >= 20)
      {
        printf("%d\n", j);
        break;
      }
    }
  }
  return 0;
}

