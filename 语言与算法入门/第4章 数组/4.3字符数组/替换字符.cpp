//�滻�ַ�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s = "abcdefg";
//������2��ʼ3���ֽڵ��ַ��滻��"123456789"
  s.replace(2,3,"123456789");
  cout<<s<<endl;  //���Ϊab123456789fg
  return 0;
}

