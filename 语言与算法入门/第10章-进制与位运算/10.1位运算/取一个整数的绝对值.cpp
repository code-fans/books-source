//取一个整数的绝对值
#include <bits/stdc++.h>
using namespace std;

int Abs(int x)
{
  int y;
  y=x>>31;
  return(x^y)-y;//也可以写作(x+y)^y
}

int main()
{
  int x;
  cin>>x;
  cout<<Abs(x);
  return 0;
}

