//�߾��ȷ��� - �����㷨
#include <bits/stdc++.h>
using namespace std;

int Remainder[101];               // remainder:��ų���������
int quotient[101];                // quotient:���δ���̵�ÿһλ
int main()
{
  //freopen("fraction.in","r",stdin);
  //freopen("fraction.out","w",stdout);
  int m,n,i,j;
  scanf("%d/%d",&m,&n);           //���뱻�����ͳ���
  cout<<m<<'/'<<n<<"=0.";
  for(i=1; i<=100; i++)           //i: �̵�λ��
  {
    Remainder[m]=i;               //m:��������remainder[m]:��������Ӧ���̵�λ��
    m*=10;                        //��������10��
    quotient[i]=m/n;              //��
    m=m%n;                        //������
    if(m==0)                      //����Ϊ0 ���ʾ������С��
    {
      for(j=1; j<=i; j++)
        cout<<quotient[j];        //�����
      cout<<endl;
      break;                      //�˳�ѭ��
    }
    if(Remainder[m]!=0)           //����������Ӧ��λ��ǰ���Ѿ����ֹ�
    {
      for(j=1; j<=i; j++)
        cout<<quotient[j];        //�����ѭ��С��
      cout<<"\nfrom "<<Remainder[m]<<" to "<<i<<"\n";
      break;
    }
  }
}

