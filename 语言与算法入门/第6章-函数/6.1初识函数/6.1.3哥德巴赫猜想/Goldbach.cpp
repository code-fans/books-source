//��°ͺղ���
#include<bits/stdc++.h>
using namespace std;

int fflag(int i)           //�ж��Ƿ�Ϊ����
{
  if(i==2)
    return 1;
  if(!(i%2))               //�����ż��,return 0
    return 0;
  int k=sqrt(i);
  for(int j=3; j<=k; j+=2)
    if(!(i%j))
      return 0;
  return 1;                //���������,return 1
}

int main()
{
  //freopen("Goldbach.in","r",stdin);
  //freopen("Goldbach.out","w",stdout);
  for(int i=4; i<=2000; i+=2)
    for(int n=2; n<i; n++) //��ż��i�ֽ�Ϊ��������
      if(fflag(n) && fflag(i-n))     //�ֱ��ж����������Ƿ��Ϊ����
      {
        printf("%d=%d+%d\n",i,n,i-n);//���������������
        break;
      }
  return 0;
}

