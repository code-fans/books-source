//ħ��ʯ���ջ� - ��ѧ����
#include <bits/stdc++.h>
using namespace std;

int ZeroTrail(int n)                      //����n����0�ĸ���
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
  if (!q)                                  //0�Ľ׳�Ϊ1
    printf ("1\n");
  else
  {
    int ans = 4*q/5*5;                     //ȷ��ansΪ5�ı���
    while (ZeroTrail(ans) < q)
      ans += 5;
    if (q == ZeroTrail(ans))
      printf ("%d\n", ans);
    else
      printf ("No solution\n");
  }
  return 0;
}

