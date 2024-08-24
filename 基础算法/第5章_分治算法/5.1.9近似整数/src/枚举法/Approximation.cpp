//近似整数－暴力枚举
#include<bits/stdc++.h>
using namespace std;
double min,A;
int n,d,L;
int main()
{
  freopen("Approximation.in", "r", stdin);
  freopen("Approximation.out", "w", stdout);

  while(scanf("%lf%d",&A,&L)!=EOF)
  {
    min=10.0;
    for(int i=1; i<=L; i++)
    {
      int j=(int)(i/A);
      if(j>L)
        continue;
      double temp=fabs(A-(double)i/j);
      if(temp<min)
      {
        min=temp;
        n=i;
        d=j;
      }
      j++;                         //分母再扩大一个数试一下
      temp=fabs(A-(double)i/j);
      if(temp<min)
      {
        min=temp;
        n=i;
        d=j;
      }
    }
    printf("%d %d\n",n,d);
  }
  return 0;
}
