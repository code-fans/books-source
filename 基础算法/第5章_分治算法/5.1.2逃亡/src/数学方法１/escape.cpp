//���� - ��ѧ����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("escape.in","r",stdin);
  freopen("escape.out","w",stdout);
  double s,b,a;
  scanf("%lf %lf %lf",&s,&b,&a);                //ע��double�������ʽ
  printf("%0.2f\n",((3*a+b)*s)/(a*(a+3*b)));
  return 0;
}
