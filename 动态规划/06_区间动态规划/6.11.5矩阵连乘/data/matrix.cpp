//��������
#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;

int	F[MAXN][MAXN];
int	R[MAXN],C[MAXN],N;              //��ά�ȷֿ������������飬���������

int main()
{
  //freopen ("matrix.in", "r", stdin);
  //freopen ("matrix.out", "w", stdout);
  scanf("%d",&N);
  for(int i=1; i<=N; ++i)           //�˴�i��1���
    scanf("%d%d",&R[i],&C[i]);

  for(int l=2; l<=N; ++l)           //lȷ����������ϲ���Ϊ2ʱ����2������ϲ�
    for(int i=1; i<=N-l+1; ++i)     //��ĳ��lֵ�µ�i�еĸ��ӵ�ֵ
    {
      int j =i+l-1;                 //ȷ���ұߵĽ���
      F[i][j]=0x7fffffff;
      for(int k=i; k<j; ++k)        //��i��j��l��������kλ�÷ָ���������
        F[i][j]=min (F[i][k]+F[k+1][j]+R[i]*C[k]*C[j],F[i][j]);
    }
  printf ("%d\n",F[1][N]);
  return 0;
}

