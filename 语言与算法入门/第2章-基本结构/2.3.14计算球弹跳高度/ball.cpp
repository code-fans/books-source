//球的弹跳高度
#include <bits/stdc++.h>
using namespace std;

int main()
{
  double h;
  cin>>h;
  double dist=h;//先加上第一次落地的距离
  int count=1;
  while(count<10)//循环一次加一次来回
  {
    count++;
    dist+=h;
    h/=2;
  }
  cout<<setprecision(3)<<fixed<<dist<<'\n'<<h/2<<'\n';
  return 0;
}

