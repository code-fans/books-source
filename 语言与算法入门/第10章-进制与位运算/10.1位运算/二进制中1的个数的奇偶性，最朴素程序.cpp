//��������1�ĸ�������ż�ԣ������س���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,x,c=0;
  cin>>x;
  for (i=1; i<=32; i++)
  {
    c=c + (x & 1);//�ж���ĩλ��0����1
    x=x >> 1;//ȥ�����ұ�һλ
  }
  cout<<( c & 1 );//�ж���ż
  return 0;
}

