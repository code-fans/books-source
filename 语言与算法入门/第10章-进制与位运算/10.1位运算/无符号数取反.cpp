//无符号数取反
#include <bits/stdc++.h>
using namespace std;

int main()
{
  unsigned short a=100;
  a = ~a;
  cout<<a<<endl; //输出65435 ,即该类型的最大值－100，而不是－101
  return 0;
}

