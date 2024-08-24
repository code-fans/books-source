//产生指定范围内的随机数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int low,hight;
  srand(time(0));
  cin>>low>>hight;//输入low,hight值，大小不得颠倒
  for(int i=1; i<=5000; i++)
    cout<<rand() %(hight-low+1)+low<<"  ";
  return 0;
}

