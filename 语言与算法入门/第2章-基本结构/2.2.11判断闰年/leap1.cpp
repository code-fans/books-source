//ÅĞ¶ÏÈòÄê1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int year,leap;
  cin>>year;
  if(year%400==0)
    cout<<"Y";
  else if(year%100!=0)
  {
    if (year%4==0)
      cout<<"Y";
    else
      cout<<"N";
  }
  else
    cout<<"N";
  return 0;
}

