//快速模幂-递推
#include<bits/stdc++.h>
using namespace std;

int Pow(int a, int b, int n)
{
  int ans=1;
  for(a%=n; b; b>>=1)     //b每次循环右移一位，直到为0结束
  {
    if(b&1)               //当前位为1
      ans=(ans*a)%n;      //将自乘x次的a加入
    a=(a*a)%n;            //a自乘x次的结果是 a^(2^x)
  }
  return ans%n;
}

int main()
{
  int a,b,n;
  //freopen("Modulo.in", "r", stdin);
  //freopen("Modulo.out","w",stdout);
  cin>>a>>b>>n;
  cout<<Pow(a,b,n)<<endl;
  return 0;
}
