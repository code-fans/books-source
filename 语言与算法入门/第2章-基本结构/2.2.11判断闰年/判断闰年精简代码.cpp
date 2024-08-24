//ÅĞ¶ÏÈòÄê¾«¼ò´úÂë
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int year;
  cin>>year;
  year%(year%100?4:400)?cout<<"N\n":cout<<"Y\n";
  return 0;
}

