//单峰排列
#include <bits/stdc++.h>
using namespace std;

int Pow(int a,int p)//二分求快速幂
{
  long long r=1,t=a;
  while(p)
  {
    if(p&1)
      r = (r*t)%1234567;
    t=(t*t)%1234567;
    p>>=1;
  }
  return (int)r;
}

int main()
{
  //freopen("unimodal.in","r",stdin);
  //freopen("unimodal.out","w",stdout);
  int p;
  scanf("%d",&p);
  printf("%d\n",Pow(2,p-1));
  return 0;
}
