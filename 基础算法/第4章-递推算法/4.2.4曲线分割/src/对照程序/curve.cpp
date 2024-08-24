//曲线分割
//当n-1个圆时，区域数为f(n-1)
//那么第n个圆就必须与前n-1个圆相交，则第n个圆被分为2（n-1）段线段，
//增加了2（n-1）个区域。
//故： f(n)=f(n-1)+2(n-1) 递推公式
//            ......
//         =f(1)+2+4+……+2(n-1)
//         =2+2*(1+2+...+n-1)
//         =n^2-n+2
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("curve.in","r",stdin);
  //freopen("curve.out","w",stdout);
  int n;
  cin>>n;
  cout<<n*n-n+2<<endl;
  return 0;
}
