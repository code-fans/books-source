//逃亡 - 数学方法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("escape.in","r",stdin);
  freopen("escape.out","w",stdout);
  double s,b,a;
  scanf("%lf %lf %lf",&s,&b,&a);                //注意double的输入格式
  printf("%0.2f\n",((3*a+b)*s)/(a*(a+3*b)));
  return 0;
}
