//ħ��ʯ���ջ� - �����㷨
#include <bits/stdc++.h>
using namespace std;

int ZeroTrail (int n)
{
  int ans = 0;
  while(n > 0)
  {
    ans+=n/5;
    n/=5;
  }
  return ans;
}

int main()
{
  //freopen("rob.in","r",stdin);
  //freopen("rob.out","w",stdout);
  int Q;
  scanf("%d", &Q);
  int start = 1;                        //��߽�
  int end = 500000000;                  //�ұ߽�
  int ans = 500000001;

  while (start <= end)                  //���ֲ���
  {
    int mid = (end +start)>>1;
    int t = ZeroTrail (mid);            //����ĩβ0�ĸ���
    if (t == Q && mid < ans)            //���������и�С��ֵ
      ans = mid;                        //����Ϊ��Сֵ
    if (t >= Q)
      end = mid - 1;
    else if ( t < Q )
      start = mid + 1;
  }
  ans != 500000001 ? printf("%d\n", ans):printf("No solution\n");
  return 0;
}

