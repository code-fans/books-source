//��������������Fibonacci��������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int f[20]= {1,1}; //f[0]=1,a[1]=1,����18��Ԫ���Զ���ֵΪ0
  for(int i=2; i<20; i++)//���±�2��ʼ���±�19
    f[i]=f[i-2]+f[i-1];//���ε���
  for(int i=0; i<20; )
  {
    printf("%5d",f[i]);
    if(++i%5==0)
      printf("\n");//5����Ϊһ��
  }
  return 0;
}

