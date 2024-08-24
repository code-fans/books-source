//左移运算符实例
#include <bits/stdc++.h>
using namespace std;

int main()
{
  short a;
  unsigned short b;
  a = 1<<16-1;//short类型长度为16位
  b = 1<<16-1;
  cout<<a<<" "<<b<<endl; //输出-32768 32767
  return 0;
}

