//����չ��������
#include <bits/stdc++.h>
using namespace std;

int fac[10]= {1,1,2,6,24,120,720,5040,40320,362880};   //�׳�
int Hash[10];

int Cantor(int m,int n)
{
  int num=0;
  int used,digit;
  m--;
  for(int i=n-1; i>0; i--)
  {
    used=0;
    digit=m/fac[i]+1;                               //�����м���������С��+1
    m%=fac[i];                                      //����m
    for(int j=1; j<=used+digit; j++)                //��֮ǰ�м������ù�
      if(Hash[j])
        used++;
    num+=(used+digit)*pow(10,i);
    Hash[used+digit]=1;                             //��Ǹ�����ʹ�ù�
  }
  for(int i=1; i<=n; i++)                           //ȡ������δʹ�õ���
    if(Hash[i]==0)
      return num+i;
}

int main()
{
  //freopen("cantor2.in","r",stdin);
  //freopen("cantor2.out","w",stdout);
  int num,n;
  cin>>num>>n;
  printf("%d\n",Cantor(n,num));
  return 0;
}

