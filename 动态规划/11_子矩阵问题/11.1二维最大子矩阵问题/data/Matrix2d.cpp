//��ά����Ӿ�������
#include <bits/stdc++.h>
using namespace std;

int sum[201][201],temp[201];          //��ʵ�������趨��temp[]
int n,m;

int Solve()
{
  int Max=-INT_MAX;
  for(int i=0; i<=n; i++)             //��i��
    for(int j=i+1; j<=n; j++)         //��j��
    {
      for(int k=1; k<=m; k++)         //���i��j�е�k�еĺ�
        temp[k]=sum[j][k]-sum[i][k];
      int sumall=0;
      for(int k=1; k<=m; k++)         //����������к�һ�����ҵ����ֵ
      {
        sumall+=temp[k];
        Max=max(Max,sumall);          //�������ֵ
        if(sumall<0)                  //�ۼ�ֵΪ����,���������ۼ�
          sumall=0;
      }
    }
  return Max;
}

int main()
{
  freopen("Matrix2d.in","r",stdin);
  freopen("Matrix2d.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1,x; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      scanf("%d",&x);
      sum[i][j]=sum[i-1][j]+x;        //ѹ������
    }
  printf("%d\n",Solve());
  return 0;
}

