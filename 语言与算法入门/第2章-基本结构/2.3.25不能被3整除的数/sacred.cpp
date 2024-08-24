//把100~200之间不能被3整除的数输出
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k=0;
  for(int n=100; n<=200; n++)
  {
    if(n%3==0)
      continue; //跳出当前循环体，执行循环体下面的语句
    if(k==0)
    {
      k++;
      cout<<n;
    }
    else
      cout<<' '<<n;
  }
  cout<<endl;
  return 0;
}

