//ȡһ�������ľ���ֵ
#include <bits/stdc++.h>
using namespace std;

int Abs(int x)
{
  int y;
  y=x>>31;
  return(x^y)-y;//Ҳ����д��(x+y)^y
}

int main()
{
  int x;
  cin>>x;
  cout<<Abs(x);
  return 0;
}

