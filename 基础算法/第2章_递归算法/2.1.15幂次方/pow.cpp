//�ݴη�
#include<bits/stdc++.h>
using namespace std;

string Dg(int n)
{
  string s;
  if(n==0)
    return "0";
  for(int i=0; n; n>>=1,i++)    //���ҵ�����λɨ��
    if(n&1)                     //��ǰ������λ��1
    {
      if(s!="")                 //�ַ�����Ϊ����Ӹ��Ӻ� 
        s="+"+s;
      if(i==1)
        s="2"+s;
      else
        s="2("+Dg(i)+")"+s;
      cout<<i<<' '<<s<<endl;
    }
  return s;
}

int main()
{
//  //freopen("pow.in","r",stdin);
//  //freopen("pow.out","w",stdout);
  int n;
  cin>>n;
  cout<<Dg(n)<<endl;
  return 0;
}
