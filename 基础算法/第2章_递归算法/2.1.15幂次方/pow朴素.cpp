//�ݴη�-���ط���
#include<bits/stdc++.h>
using namespace std;

int Dg(int n)
{
  int j=1,i=0;
  for(; j*2<=n; i++)    //�ҵ�����ָ��
    j<<=1;              //j=j*2
  if(i==1)
    cout<<"2";
  if(i==0)
    cout<<"2(0)";
  if(i>1)
  {
    cout<<"2(";
    Dg(i);              //��ǰ�ҵ������ָ�������ݹ�
    cout<<")";
  }
  if(n-j>0)
  {
    cout<<"+";
    Dg(n-j);
  }
}

int main()
{
  freopen("pow.in","r",stdin);
  freopen("pow.out","w",stdout);
  int n;
  cin>>n;
  Dg(n);//ֱ�ӵ���
  cout<<endl;
  return 0;
}
