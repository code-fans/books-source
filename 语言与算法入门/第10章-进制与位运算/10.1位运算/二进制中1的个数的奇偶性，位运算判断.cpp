//二进制中1的个数的奇偶性，位运算判断
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin>>x;
  x=x ^ (x >> 1);
  x=x ^ (x >> 2);
  x=x ^ (x >> 4);
  x=x ^ (x >> 8);
  x=x ^ (x >> 16);
  cout<<(x&1)<<endl;
  return 0;
}

