//利用排列组合优化
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,count=0;
  for(i=1; i<=9; i++)
    count+=2*i-1;
  cout<<count<<endl;
  return 0;
}

