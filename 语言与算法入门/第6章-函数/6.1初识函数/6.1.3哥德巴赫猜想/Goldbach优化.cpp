//��°ͺղ��롪ɸѡ��Ԥ����
#include<bits/stdc++.h>
using namespace std;
bool p[10005];                           //��������

void GetPrime()                          //Ԥ�������������
{
  for(int i=2; i<=2000; i++)
    p[i]=true;
  int m=sqrt(2000);
  for(int i=2; i<=m; i++)
    if(p[i])
      for(int j=i*i; j<=2000; j+=i)
        p[j]=false;
}

int main()
{
  GetPrime();
  for(int i=4; i<=2000; i+=2)
    for(int n=2; n<i; n++)            //��ż��i�ֽ�Ϊ��������
      if(p[n] && p[i-n])
      {
        printf("%d=%d+%d\n",i,n,i-n); //���������������
        break;
      }
  return 0;
}


