//string的部分操作方法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s="Hi,..morn";           //定义了名为s的string类并初始化
  s=s+"ing";                      //尾部添加字符串"ing"
  cout<<"添加字符串:"<<s<<endl;   //输出"Hi,..morning"
  s.erase(3,2);                   //删除第3个字符后的2个字符
  cout<<"删除字符串:"<<s<<endl;   //输出"Hi,morning"
  int f=s.find("Hi,");            //查找"Hi,"在s中的位置,-1为找不到
  s.insert(f+3,2,'G');            //在f+3个位置后插入单个字符'G'2次
  cout<<"插入两字符:"<<s<<endl;   //输出"Hi,GGmorning"
  s.insert(5,",MM,");             //在第5个位置后插入字符串",MM,"
  cout<<"插入字符串:"<<s<<endl;   //输出"Hi,GG,MM,morning"
  string v=s.substr(4,3);         //取s中第4个位置后的3个字符给v
  cout<<"字符串子串:"<<v<<endl;   //输出"G,M"
  cout<<"string长度:"<<v.length();//输出3,即v的长度
  return 0;
}

