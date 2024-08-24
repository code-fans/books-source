//位优化快速幂运算
#include <bits/stdc++.h>
using namespace std;

unsigned long long Pow(unsigned long long X, unsigned long long n)//非递归
{
  unsigned long long result=1;
  if (n == 0)
    return 1;
  else
    while (n)
    {
      if (n & 1)
        result *= X;
      X *= X;
      n >>= 1;
    }
  return result;
}

int main()
{
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  int X,n;
  cin>>X>>n;
  cout<<Pow(X,n)<<endl;
  return 0;
}
