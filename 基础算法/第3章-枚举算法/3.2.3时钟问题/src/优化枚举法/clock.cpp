//ʱ������
#include <bits/stdc++.h>
using namespace std;

int C[10], P[10];

int Order(int k)                              //ͳһ��ɷ�Χ��ֵ�ĺ���
{
  while (k < 0)
    k += 4;
  while (k > 4)
    k -= 4;
  return k;
}

int main()
{
  freopen("clock.in","r",stdin);
  freopen("clock.out","w",stdout);
  for (int i = 1; i <= 9; ++i)
  {
    scanf("%d", &C[i]);
    C[i]=(4-C[i])%4;                             //C[i]:��i������Ҫת����
  }
  for (P[1] = 0; P[1] <= 3; ++P[1])              //ö����ת����1
    for (P[2] = 0; P[2] <= 3; ++P[2])            //ö����ת����2
      for (P[3] = 0; P[3] <= 3; ++P[3])          //ö����ת����3
      {
        P[4]=Order(C[1]-P[1]-P[2]);
        P[5]=Order(C[2]-P[1]-P[2]-P[3]);
        P[6]=Order(C[3]-P[2]-P[3]);
        P[7]=Order(C[4]-P[1]-P[4]-P[5]);
        P[9]=Order(C[6]-P[3]-P[5]-P[6]);         //�����P[9]
        P[8]=Order(C[8]-P[5]-P[7]-P[9]);         //�������P[8]
        if ( (P[4]+P[7]+P[8]) % 4==C[7] && (P[6]+P[8]+P[9]) % 4==C[9]
             && (P[1]+P[3]+P[5]+P[7]+P[9])%4==C[5])
        {
          for (int i = 1; i <= 9; ++i)           //���������ֻҪ��һ��
            for (int k = 1; k <= P[i]; ++k)
              printf("%d", i);
          printf("\n");
          return 0;
        }
      }
  printf("No Answer!\n");
  return 0;
}

