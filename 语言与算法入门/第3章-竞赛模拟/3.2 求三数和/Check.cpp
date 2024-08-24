//测试程序
#include <bits/stdc++.h>
using namespace std;

int main()
{
  for(int i=1; i<=7; i++)
  {
    string F="sum";
    F+=char(i+48);             //整数i转为字符i,'0'的ASCII值为48
    string s="copy "+ F+".in sum.in";
    system(s.c_str());
    int time1=clock();
    system("sum.exe");
    int time2=clock();
    string Cmd="fc sum.out "+F+".ans";
    if(!system(Cmd.c_str()))
      cout<<"                   测试点"<<i<<"通过，用时"<<time2-time1<<"毫秒\n\n";
  }
  return 0;
}

