//����ģ��-����
#include<bits/stdc++.h>
using namespace std;

int Pow(int a, int b, int n)
{
  int ans=1;
  for(a%=n; b; b>>=1)     //bÿ��ѭ������һλ��ֱ��Ϊ0����
  {
    if(b&1)               //��ǰλΪ1
      ans=(ans*a)%n;      //���Գ�x�ε�a����
    a=(a*a)%n;            //a�Գ�x�εĽ���� a^(2^x)
  }
  return ans%n;
}

int main()
{
  int a,b,n;
  //freopen("Modulo.in", "r", stdin);
  //freopen("Modulo.out","w",stdout);
  cin>>a>>b>>n;
  cout<<Pow(a,b,n)<<endl;
  return 0;
}
