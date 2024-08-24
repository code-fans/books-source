//异或加密
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x=1314520;
  x=x^12345678;
  cout<<"加密后的值为："<<x<<endl;
  x=x^12345678;
  cout<<"解密后的值为："<<x<<endl;
  return 0;
}

