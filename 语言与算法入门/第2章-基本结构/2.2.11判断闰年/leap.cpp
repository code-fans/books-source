//ÅĞ¶ÏÈòÄê
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int year;
  cin>>year;
  if(year%400==0 || (year%4==0 && year%100!=0))
    cout<<"Y\n";
  else
    cout<<"N\n";
  return 0;
}

