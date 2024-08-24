//string类的部分操作符的使用
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1,s2="abc";     //定义s1为空字符串，s2赋值为"abc"
  cin>>s1;
  cout<<(s1==s2 ? "s1==s2":"s1!=s2")<<endl;
  cout<<(s1>=s2 ? "s1>=s2":"s1<s2" )<<endl;
  s1="new";               //s1更新为"new"
  s1=s1+'_';              //s1更新为"new_"
  s1+=s2;                 //s2连接到s1的后面,s1为"new_abc"
  for(int i=s1.length()-1; i>=0; i--)
    cout<<s1[i];          //逆序逐个输出各元素即"cba_wen"
  return 0;
}

