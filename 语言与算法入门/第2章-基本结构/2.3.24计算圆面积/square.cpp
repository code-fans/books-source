//����Բ���
#include <bits/stdc++.h>
using namespace std;

int main()
{	
  for(int r=1;r<=10;r++)
  {
    double area=3.14*r*r;
    if(area>100)
      break; //������ǰѭ���壬ִ��ѭ������������
    cout<<r<<":area="<<setprecision(2)<<fixed<<area<<endl;
  }
  return 0;
}

