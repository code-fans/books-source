//快速模幂 －递归
//根据公式(a*b)%c =(a%c * b%c)%c
#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int Pow(int a, int b)
{
  if (b == 1)
    return a % c;
  else if (b==0)
    return 1;
  int t = Pow(a, b>>1);
  return (b & 1) ? (t*t*a) % c : (t*t) % c;
}

int main()
{
  freopen("Modulo.in", "r", stdin);
  freopen("Modulo.out","w",stdout);
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", Pow(a,b)%c);
  return 0;
}
