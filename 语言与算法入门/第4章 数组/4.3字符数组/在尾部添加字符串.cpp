//��β������ַ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s = "abc";
  s += "def";  //��β����ַ���def
  cout<<s<<endl;
  s.append("1234");    //append()����������ĩβ����ַ���
  cout<<s<<endl;
  s.push_back('z');    //push_back()����ֻ����ĩβ���һ���ַ�
  cout<<s<<endl;
  return 0;
}

