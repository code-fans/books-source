//��ʵ������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  float a,b,t; //a:����ƿb:��ƿt:��ƿ
  cin>>a>>b;
  if(a>b)
  {
    t=a;  //���͵����ƿ
    a=b;  //�׵��뽴��ƿ
    b=t;  //�����ڿ�ƿ�Ľ��͵����ƿ
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}

