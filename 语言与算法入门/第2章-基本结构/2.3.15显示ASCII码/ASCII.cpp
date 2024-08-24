//显示ASCII码
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n=0;
  for(int i=15; i<128; i++)
  {
    cout <<setw(4)<<i<<":"<<setw(1)<<char(i);
    if (!(++n%10))
      cout<<endl;//每显示十个换一行
  }
  cout<<endl;
  return 0;
}

