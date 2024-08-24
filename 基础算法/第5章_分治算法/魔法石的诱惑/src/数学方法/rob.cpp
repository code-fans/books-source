//魔法石的诱惑 - 数学方法
#include <bits/stdc++.h>
using namespace std;

int ZeroTrail(int n)                      //计算n！的0的个数
{
  int count = 0;
  for(; n; n/=5)
    count+=n/5;
  return count;
}

int main()
{
  freopen("rob.in","r",stdin);
  freopen("rob.out","w",stdout);
  int q;
  scanf ("%d", &q);
  if (!q)                                  //0的阶乘为1
    printf ("1\n");
  else
  {
    int ans = 4*q/5*5;                     //确保ans为5的倍数
    while (ZeroTrail(ans) < q)
      ans += 5;
    if (q == ZeroTrail(ans))
      printf ("%d\n", ans);
    else
      printf ("No solution\n");
  }
  return 0;
}

