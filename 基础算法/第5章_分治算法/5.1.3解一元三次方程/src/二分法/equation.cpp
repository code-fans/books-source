//һԪ���η��̣����ַ�
#include <bits/stdc++.h>
using namespace std;

double a,b,c,d;
double ans[4];
int n;

double Fun(double x)          //����x�󷽳̸�
{
  return ((a*x+b)*x+c)*x+d;
}

void Calc(double l,double r)  //���ֲ��ҽ�
{
  if(n>2 || l>r || (Fun(l)*Fun(r)>0 && r-l<1))
    return ;                  //�ҵ�ȫ�����������޽��˳�
  double mid=(l+r)/2;
  if(fabs(Fun(mid))<=1e-4)    //�ҵ�һ����
  {
    ans[++n]=mid;             //���δ����
    Calc(l,mid-1);            //�����֮��ľ���ֵ��1
    Calc(mid+1,r);
  }
  else
  {
    Calc(l,mid);
    Calc(mid,r);
  }
}

int main()
{
  freopen("equation.in","r",stdin);
  freopen("equation.out","w",stdout);
  cin>>a>>b>>c>>d;
  Calc(-100,100);
  sort(ans+1,ans+4);          //��������С��������
  cout<<setprecision(2)<<fixed<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<'\n';
  return 0;
}
