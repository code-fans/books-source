//校庆日
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int day=20-1;
  cout<<"共经过了："<<day/7<<"星期，多"<< day%7<<"天"<<"\n";
  cout<<"答案是星期"<< (6+ day%7)%7 <<"\n";
  return 0;
}

