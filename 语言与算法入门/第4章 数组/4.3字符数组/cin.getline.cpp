//cin.getline()的使用
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[40];           //实际只能输入39个字符，最后一位用于标记结束 
  cin.getline(a,39);    //输入a b c d e f g
  cout<<a<<endl;        //输出a b c d e f g
  cin.getline(a,80,'e');//输入a b c d e f g
  cout<<a<<endl;        //因为'e'为结束字符，所以输出a b c d 
  return 0;
}

