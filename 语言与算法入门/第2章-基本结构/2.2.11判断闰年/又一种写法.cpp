#include<bits/stdc++.h>
using namespace std;

int main()
{
  int year;
  cin>>year;
  if(year%100==0)//百年不闰，所以直接除了
    year/=100;
  if(year%4==0)//四年一闰
    cout<<"Y\n";
  else
    cout<<"N\n";
  return 0;
}
