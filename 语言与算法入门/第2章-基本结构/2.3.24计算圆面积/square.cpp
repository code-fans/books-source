//计算圆面积
#include <bits/stdc++.h>
using namespace std;

int main()
{	
  for(int r=1;r<=10;r++)
  {
    double area=3.14*r*r;
    if(area>100)
      break; //跳出当前循环体，执行循环体下面的语句
    cout<<r<<":area="<<setprecision(2)<<fixed<<area<<endl;
  }
  return 0;
}

