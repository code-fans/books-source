//ħ����
#include<bits/stdc++.h>
using namespace std;
int a[10]= {0,0,0,0,0,5,0,0,0,0},num=0;

int Fun(int m)
{
  if(m==5)
  {
    for(int j=1; j<=3; ++j)           //���ħ�����Ƿ����
      if(a[j]+a[j+3]+a[j+6]!=15 || a[3*j]+a[3*j-1]+a[3*j-2]!=15)
        return 0;
    printf("%d%d%d\n",a[1],a[2],a[3]);//�������������
    printf("%d%d%d\n",a[4],a[5],a[6]);
    printf("%d%d%d\n\n",a[7],a[8],a[9]);
    num++;
  }
  else
    for(int i=1; i<=9; ++i)           //ö��9������
      if(a[i]==0)                     //����ø���δ����
      {
        a[i]=m;                       //�ø�������
        a[10-i]=10-m;                 //��Ӧ��������
        Fun(m+1);                     //�ݹ�����һ����
        a[i]=0;                       //Ҫ�ָ�ԭ��,�����޷�������������
        a[10-i]=0;                    //Ҫ�ָ�ԭ��,�����޷�������������
      }
}

int main()
{
  freopen("matrix.in","r",stdin);
  freopen("matrix.out","w",stdout);
  Fun(1);                             //������1��ʼ��
  printf("%d\n",num);
  return 0;
}

