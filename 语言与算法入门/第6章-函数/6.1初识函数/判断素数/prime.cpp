//�ж���������
#include <bits/stdc++.h>
using namespace std;
void prime(int number);//���Ӻ���������

int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  int num;
  scanf("%d",&num);
  prime(num);
  return 0;
}

void prime(int number)  //���践��ֵʱ������ǰ�����void
{
  int flag=1,k=sqrt(number);//flagΪ�Ƿ������ı��
  for(int n=2; n<=k; ++n)
    if(number%n==0)
    {
      flag=0;
      break;
    }
  flag?printf("1\n"):printf("0\n");
}

