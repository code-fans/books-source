//f[i][j][k]��ʾ��һ�д�����i�����ڶ��д�����j������ѡȡ��k���Ӿ��������ֵ��
//ת�ƵĻ�Ҫ������ߣ���һ�У�ѡ��һ�飬Ҫ�����ұߣ��ڶ��У�ѡ��һ�飬�ֻ���
//���ж�ռ�ľ��Σ�����ֻ��i��j��Ȳſ������ж�ռ�������޷��պõ���i��
//luguo 2331
#include<bits/stdc++.h>
using namespace std;

int dp[150][11],f[150][150][11];
int sum[2][150];

int main()
{
  int n,m,k,t1,t2;
  cin>>n>>m>>k;
  if(m==1)                        //����ֻ��һ�е����,������������Ҫ�õ�
  {
    for(int i=1; i<=n; i++)
    {
      cin>>t1;
      sum[0][i]=sum[0][i-1]+t1;   //ǰ׺��
    }
    for(int K=1; K<=k; K++)       //ö���Ӿ������
      for(int j=0; j<=n; j++)     //dp[i][k]��ʾ����i�У�ѡ��k���Ӿ������ֵ
        for(int i=j; i<=n; i++)   //ö����
          dp[i][K]=max(dp[i][K],max(dp[j][K-1]+sum[0][i]-sum[0][j],dp[i-1][K]));//ѡ����ѡ 
    printf("%d\n",dp[n][k]);
  }
  else
  {
    for(int i=1; i<=n; i++)
    {
      cin>>t1>>t2;
      sum[0][i]=sum[0][i-1]+t1;     //sum[0][i]��ʾ��һ�е�ǰ׺��
      sum[1][i]=sum[1][i-1]+t2;     //sum[1][i]��ʾ�ڶ��е�ǰ׺��
    }
    for(int l=1; l<=k; l++)         //ѡk�������k�������
      for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
          //f[i][j][k]��ʾ��һ�д�����i�����ڶ��д�����j������ѡȡ��k���Ӿ��������ֵ
          f[i][j][l]=max(f[i-1][j][l],f[i][j-1][l]);
          for(int s=0; s<i; s++)
            f[i][j][l]=max(f[i][j][l],f[s][j][l-1]+sum[0][i]-sum[0][s]); //ö�ٴ����ת��
          for(int s=0; s<j; s++)
            f[i][j][l]=max(f[i][j][l],f[i][s][l-1]+sum[1][j]-sum[1][s]); //ö�ٴ��ұ�ת��
          if(i==j)
            for(int s=0; s<i; s++)                                       //ö�ٴ�����ת��
              f[i][j][l]=max(f[i][j][l],f[s][s][l-1]+sum[0][i]-sum[0][s]+sum[1][j]-sum[1][s]);
        }
    printf("%d\n",f[n][n][k]);
  }
  return 0;
}
