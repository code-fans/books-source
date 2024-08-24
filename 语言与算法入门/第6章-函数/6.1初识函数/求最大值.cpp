//求最大值
#include <bits/stdc++.h>
using namespace std;

float Max(float a,float b,float c)
{
  return max(max(a,b),c);
}

int main()
{
  float x,y,z;
  cin>>x>>y>>z;
  cout<<Max(x,y,z)<<endl;
  return 0;
}

