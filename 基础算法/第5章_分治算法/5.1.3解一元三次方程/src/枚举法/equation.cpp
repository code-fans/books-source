//һԪ���η��̼�ö�ٷ�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  double a,b,c,d,fx,x,num=0;
  int i;
  //freopen("equation.in","r",stdin);
  //freopen("equation.out","w",stdout);
  cin>>a>>b>>c>>d;
  cout.precision(2);//�辫�ȣ���С����λ��
  cout.setf(ios::fixed);// �Զ�����ʽ��ʾ������
  for (i=-10000,x=-100; i<=10000; x=(++i)/100.0) //xһ��Ҫ����ֵ
  {
    fx=a*x*x*x+b*x*x+c*x+d;
    if (fx>=-1e-10 && fx<=1e-10)
      ++num!=3?cout<<x<<' ':cout<<x<<endl;
  }
  return 0;
}
