//��ĵ����߶�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  double h;
  cin>>h;
  double dist=h;//�ȼ��ϵ�һ����صľ���
  int count=1;
  do
  {
    count++;
    dist+=h;
    h/=2;
  }
  while(count<10);
  cout<<setprecision(3)<<fixed<<dist<<'\n'<<h/2<<'\n';
  return 0;
}

