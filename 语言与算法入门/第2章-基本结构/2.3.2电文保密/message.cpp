//���ı���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char c;
  while((c=getchar())!='\n')//getchar���Ӽ��̻�ȡһ���ַ�
  {
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))//���ַ�ΪӢ����ĸʱ
    {
      c+=4;
      if(c>'Z' && c<='Z'+4 || c>'z') //����Ascii�������Ϊʲô����д
        c-=26;
    }
    cout<<c;
  }
  cout<<endl;
  return 0;
}

