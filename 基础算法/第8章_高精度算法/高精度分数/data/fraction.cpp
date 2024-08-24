//�߾��ȷ����Ż��㷨
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int Delay(int x)                          //�����ӳ�����λ��
{
  int n2=0,n5=0;
  while(x%2==0)
  {
    n2++;
    x/=2;
  }
  while(x%5==0)
  {
    n5++;
    x/=5;
  }
  return n2>n5?n2:n5;
}

int Gcd(int a, int b)                     //ŷ����õ��������Լ��
{
  return a%b?Gcd(b,a%b):b;
}

int Repetend(int x)                       //����ѭ����λ��
{
  int digit,k=9;
  while(x%2==0)                           //�������г�ȥ����2��5
    x/=2;
  while(x%5==0)
    x/=5;
  for(digit=1; digit<=MAXN; ++digit)      //������С��kֵ������10^k��1��x����
  {
    if(k%x==0)
      break;
    k=k%x*10+9;
  }
  return digit;
}

void compute(int m,int n,int delay,int repetend)
{
  int digit=delay+repetend;
  for(int i=1; i<=digit; ++i)
  {
    m*=10;                               //��������10λ
    cout<<m/n;
    m%=n;                                //����һ������
    if(m==0)                             //����Ϊ0,��Ϊ����С��
    {
      printf("\n");
      return;                           //�˳�ѭ��
    }
  }
  printf("\n");
  cout<<"from "<<delay+1<<" to "<<digit<<"\n";
}

int main()
{
  //freopen("fraction.in","r",stdin);
  //freopen("fraction.out","w",stdout);
  int m,n;
  scanf("%d/%d",&m,&n);
  printf("%d/%d=0.",m,n);
  int gcd=Gcd(m,n);                           //�����Լ��
  m/=gcd;
  n/=gcd;
  compute(m,n,Delay(n),Repetend(n));
  return 0;
}

