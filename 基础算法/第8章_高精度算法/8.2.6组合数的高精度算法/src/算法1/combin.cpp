//������߾����㷨1-�Ǹ߾���
#include <bits/stdc++.h>
using namespace std;

const int MAX = 90000000;
long long C[MAX][2];

void Combin(int M,int N)
{
  int M1=0, M2=1;
  C[0][M1] = 1;                     //��ʾC(1,0)=1
  C[1][M1] = 1;                     //��ʾC(1,1)=1

  for(int i = 2; i <= M; ++i)       //����M<=1000000�����㼫Ϊ��ʱ
  {
    C[0][M2] = C[i][M2] = 1;        //��ʾC(i,0)=1,��ʾC(i,i)=1
    for(int j = 1; j < i; ++j)
    {
      C[j][M2] = C[j-1][M1] + C[j][M1];
      if (j>=N)                      //�Ż���֦
        break;
    }
    swap(M1,M2);                     //�������齻��ֵ
  }
  printf("%lld\n",C[N][M1]);
}

int main()
{
  //freopen("combin.in","r",stdin);
  //freopen("combin.out","w",stdout);
  int m, n;
  scanf("%d%d",&m,&n);
  m=m+n-2;
  Combin(m,--n);
  return 0;
}

