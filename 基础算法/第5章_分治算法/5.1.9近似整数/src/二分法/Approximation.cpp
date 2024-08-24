//近似整数 —二分法
#include <bits/stdc++.h>
using namespace std;

struct Elem
{
  int a, b;
} ans;

double A;
int L;

int Bsearch(int d)
{
  int l = 1;
  int r = min(L, d * 10);
  while (l < r)
  {
    int mid = (l + r)>>1;
    if (mid * 1.0 / d < A)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

void FindMin(int n, int d)
{
  if(abs(n*1.0/d) < abs(ans.a*1.0/ans.b))
  {
    ans.a = n;
    ans.b = d;
  }
}

int main()
{
  freopen("Approximation.in", "r", stdin);
  freopen("Approximation.out", "w", stdout);
  scanf("%lf%d", &A, &L);
  ans.a = (int)(A + 0.5);
  ans.b = 1;
  if (ans.a == 0)
    ans.a = 1;
  if (ans.a > L)
    ans.a = L;
  for (int d = 2; d <= L; d++)//枚举d 
  {
    int n = Bsearch(d);//二分查找n 
    FindMin(n, d);     //更新最优解 
    if (n > 1)
      FindMin(n - 1, d);//尝试分子减1 
  }
  printf("%d %d\n", ans.a, ans.b);
  return 0;
}
