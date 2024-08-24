//用数组来处理求Fibonacci数列问题
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("fibonacci.in","r",stdin);
  //freopen("fibonacci.out","w",stdout);
  int f[20]= {1,1}; //a[0]=1,a[1]=1,其余１８个元素自动赋值为0
  for(int i=2; i<20; i++)
    f[i]=f[i-2]+f[i-1];//依次递推
  for(int i=0; i<20; i++)
    cout<<f[i]<<endl;
  return 0;
}
