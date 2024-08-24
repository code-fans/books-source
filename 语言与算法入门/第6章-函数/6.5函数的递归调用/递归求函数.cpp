//µÝ¹éÇóº¯Êý
#include <bits/stdc++.h>
using namespace std;

double px(double x,int n)
{
  if (n==1)
    return x;
  else
    return x*(1-px(x,n-1));
}

int main()
{
  double x;
  int n;
  scanf("%lf %d",&x,&n);
  printf("%f\n",px(x,n));
  return 0;
}

