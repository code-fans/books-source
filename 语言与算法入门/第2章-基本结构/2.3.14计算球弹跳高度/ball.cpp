//��ĵ����߶�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  double h;
  cin>>h;
  double dist=h;//�ȼ��ϵ�һ����صľ���
  int count=1;
  while(count<10)//ѭ��һ�μ�һ������
  {
    count++;
    dist+=h;
    h/=2;
  }
  cout<<setprecision(3)<<fixed<<dist<<'\n'<<h/2<<'\n';
  return 0;
}

