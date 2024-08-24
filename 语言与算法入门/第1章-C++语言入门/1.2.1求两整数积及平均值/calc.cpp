/*
  这个程序的名字叫求两整数积及平均值，它真的太强大了！好吧，
  这么说有点无聊，但反正是注释语句，随便怎么写，不影响程序运行的
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c;                    //定义变量 a,b,c，此时a,b,c的值未知
  cin>>a>>b;                    //输入a和b的值
  c=a*b;                        //计算a和b的乘积，把结果赋值给c
  cout<<a<<"*"<<b<<"="<<c<<endl;//输出的变量和字符串要用"<<"隔开
  cout<<(a+b)/2<<endl;          //整数除整数会舍去小数部分，自动取整
  return 0;
}

