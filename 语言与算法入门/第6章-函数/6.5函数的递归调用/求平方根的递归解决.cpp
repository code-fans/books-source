//��ƽ�����ĵݹ���
#include <bits/stdc++.h>
using namespace std;

double SquareRoot(double a,double x0)
{
  double x1=(x0+a/x0)/2;
  if(fabs(x1-x0)>1e-8)
    return SquareRoot(a,x1);
  else
    return x1;
}

int main()
{
  double x;
  scanf("%lf",&x);
  printf("%f\n",SquareRoot(x,1.0));//���Խ�1.0��Ϊ����ֵ���ԣ�
  return 0;
}

