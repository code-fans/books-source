//����������׷�Ϸ�
#include <bits/stdc++.h>
using namespace std;

int L;
double A;

int main()
{
  //freopen("Approximation.in", "r", stdin);
  //freopen("Approximation.out", "w", stdout);
  scanf("%lf%d", &A, &L);
  int ansn, ansd;
  int n = 1, d = 1;                    //��ʼ���Ӻͷ�ĸ����Ϊ1
  double min = 1e9, cha;
  while(n <= L && d <= L)
  {
    cha = A - (double)n / d;
    if (min > fabs(cha))               //�������Ž�
    {
      min = fabs(cha);
      ansn = n;
      ansd = d;
    }
    cha>0?n++:d++;
  }
  printf("%d %d\n", ansn, ansd);
}
