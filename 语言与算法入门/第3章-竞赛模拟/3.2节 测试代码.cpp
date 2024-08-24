#include <bits/stdc++.h>
using namespace std;

int main()
{
  for(int i=1; i<=5; i++)   //5组测试数据，所以循环5次
  {
    string F="test";
    F+=char(i+48);         //整数i转为字符i,'0'的ASCII值为48
    //拷贝命令，例如i=1时,为"copy test1.in test.in"
    string s="copy "+ F+".in test.in";
    system(s.c_str());      //执行拷贝命令
    int time1=clock();      //获取当前运行时钟数
    system("test.exe");     //执行test.exe文件
    int time2=clock();      //程序运行结束后的时钟数
    //比较文件命令,例如i=1时,为"fc test.out test1.ans";
    string Cmd="fc test.out "+F+".ans";
    if(!system(Cmd.c_str()))//执行比较文件命令
      cout<<" 测试点"<<i<<"通过，用时"<<time2-time1<<"毫秒\n\n";
  }
  return 0;
}

