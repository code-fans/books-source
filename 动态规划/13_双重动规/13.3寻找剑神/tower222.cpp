//��Ϊ�����˻������ڶ�̬�滮���˺�Ч��
#include<bits/stdc++.h>
using namespace std;

int a[1000][1000],dp[1000][1000];//d[i][j]��ʾ�ӣ�i��j�����λ�õ���ײ����̾���

int main()
{
  //freopen("tower.in","r",stdin);
  //freopen("tower.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    for(int j=0; j<=i; j++)
    {
      scanf("%d",&a[i][j]);
      dp[i][j]=1e9;
    }
  for(int i=0; i<n; i++)
  {
    dp[n-1][i]=a[n-1][i];
    dp[n-1][i]=dp[n-1][i-1]+a[n-1][i];  //��Ϊ���һ���ұߵĵ�ֻ�ܴ���ߵ�����������Ԥ����
  }
  for(int i=n-1; i>=0; i--)
    dp[n-1][i]=min(dp[n-1][i],dp[n-1][(i+1)%n]+a[n-1][i]); //�����ߵĻ����϶�Ҫ�ȴ���߷���ȥ��������

  for(int i=n-2; i>=0; i--)                   //�ӵ�������
  {
    dp[i][0]=min(dp[i+1][0],dp[i+1][1]);     //����߽�Ĵ���
    dp[i][0]=min(dp[i][0],dp[i+1][i+1]);
    dp[i][0]+=a[i][0];

    dp[i][i]=min(dp[i+1][0],dp[i+1][i]);    //���ұ߽�Ĵ���
    dp[i][i]=min(dp[i][i],dp[i+1][i+1]);
    dp[i][i]+=a[i][i];

    for(int j=1; j<=i-1; j++)                  //���м�λ�õĴ�����ʱ�������һ���Ѿ���������
      dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+a[i][j];

    dp[i][0]=min(dp[i][0],dp[i][i]+a[i][0]);    //����������
    for(int j=1; j<=i; j++)
      dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
    for(int j=i; j>=0; j--)
      dp[i][j]=min(dp[i][j],dp[i][(j+1)%(i+1)]+a[i][j]);
  }
  printf("%d\n",dp[0][0]);
  return 0;
}
