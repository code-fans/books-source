//�����㷨��߾��Ƚ׳�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("factorial.in","r",stdin);
  freopen("factorial.out","w",stdout);
  int data[50001]= {0,1};
  int n,digit=1;                             //λ��
  scanf("%d",&n);
  for(int i=1; i<n+1; i++)
  {
    for(int j=1; j<digit+1; j++)             //�׳�����
      data[j]*=i;
    for(int j=1; j<digit+1; j++)
      if(data[j]>=10)                        //��ĳλ��>=10ʱ������������
        for(int r=1; r<digit+1; r++)
        {
          if(data[digit]>=10)                //λ������1
            digit++;
          data[r+1]+=data[r]/10;
          data[r]=data[r]%10;
        }
  }
  printf("%d!=",n);                          //��ӡ���
  for(int k=digit; k>0; k--)
    printf("%d",data[k]);
  printf("\n");
  return 0;
}

