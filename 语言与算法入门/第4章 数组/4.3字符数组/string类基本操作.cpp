//string��Ĳ��ֲ�������ʹ��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1,s2="abc";     //����s1Ϊ���ַ�����s2��ֵΪ"abc"
  cin>>s1;
  cout<<(s1==s2 ? "s1==s2":"s1!=s2")<<endl;
  cout<<(s1>=s2 ? "s1>=s2":"s1<s2" )<<endl;
  s1="new";               //s1����Ϊ"new"
  s1=s1+'_';              //s1����Ϊ"new_"
  s1+=s2;                 //s2���ӵ�s1�ĺ���,s1Ϊ"new_abc"
  for(int i=s1.length()-1; i>=0; i--)
    cout<<s1[i];          //������������Ԫ�ؼ�"cba_wen"
  return 0;
}

