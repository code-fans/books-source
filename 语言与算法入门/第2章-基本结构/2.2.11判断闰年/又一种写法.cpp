#include<bits/stdc++.h>
using namespace std;

int main()
{
  int year;
  cin>>year;
  if(year%100==0)//���겻������ֱ�ӳ���
    year/=100;
  if(year%4==0)//����һ��
    cout<<"Y\n";
  else
    cout<<"N\n";
  return 0;
}
