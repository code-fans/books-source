//��������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int f1=1,f2=1;
  for(int i=1; i<=20; i++)
  {
    cout<<f1<<' '<<f2;
    if(i%2==0)  //��һ���������f1��f2����4�����֣���ֵ������һ��
      cout<<'\n';
    else
      cout<<" ";
    f1=f1+f2;   //����ǰ��
    f2=f2+f1;
  }
  return 0;
}

