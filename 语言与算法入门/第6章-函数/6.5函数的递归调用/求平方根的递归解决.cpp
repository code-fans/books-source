//求平方根的递归解决
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
  printf("%f\n",SquareRoot(x,1.0));//尝试将1.0改为其他值试试？
  return 0;
}

