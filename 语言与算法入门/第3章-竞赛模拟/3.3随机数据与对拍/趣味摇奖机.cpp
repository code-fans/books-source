//Ȥζҡ����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));//srand()ȡ��ǰʱ����Ϊ���������
  int t=rand()%10;   //rand()����0~32767֮��������
  cout<<"     *** Ȥζҡ���� ***  \n\n";
  cout<<"����ѡһ������(0~9):  ";
  int j;
  cin>>j;
  if(j<0 || j>9)        //��������ֲ��Ϲ�
    return 0;

  if(j==t)
    cout<<"\n��,�صȽ�!��������!";
  else if(abs(j-t)<=1)
    cout<<"\nһ�Ƚ�!�ܲ���ѽ!";
  else if(abs(j-t)<=2)
    cout<<"\n���Ƚ�!Ҳ������...";
  else if(abs(j-t)<=3)
    cout<<"\n���Ƚ�!��ҪŬ��Ŷ...";
  else
    cout<<"\n���ϧ!ʲô��û��...";
  return 0;
}

