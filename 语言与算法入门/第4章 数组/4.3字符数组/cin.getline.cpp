//cin.getline()��ʹ��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[40];           //ʵ��ֻ������39���ַ������һλ���ڱ�ǽ��� 
  cin.getline(a,39);    //����a b c d e f g
  cout<<a<<endl;        //���a b c d e f g
  cin.getline(a,80,'e');//����a b c d e f g
  cout<<a<<endl;        //��Ϊ'e'Ϊ�����ַ����������a b c d 
  return 0;
}

