//��dp[i][j]Ϊ�����һ��ʯͷ��ѹ��i�²��ԣ�j��ʯͷ�жϳ�ѹ��ֵ�����ٴ�����
//�����һ��ʯͷ��ѹ��i�²��ԣ�������ˣ���ô����Ҫ��1~i-1ѹ��ֵ�м���Ѱ�ң�
//����Ҫ�Ĵ���Ϊdp[i-1][j-1]��û��Ļ�����Ҫ��i+1~n�м���Ѱ�ң�����Ҫ�Ĵ���Ϊdp[n-i][j]��
//���Ծ͵õ��˵��Ʒ���dp[i][j] = dp[i-1][j-1] + dp[n-i][j]��
//
//��ʼ״̬Ϊ
//n == 0 || m == 0ʱ������Ϊ0
//n == 1ʱ������1����n��ѹ�����n�Σ����Գ�ʼ��Ϊdp[i][]��ʼ��Ϊi
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N];

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  int n,m;
  while(~scanf("%d%d",&n,&m))
  {
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= m; j++)
        dp[i][j] = i;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= i; j++)
        for(int k = 2; k <= m; k++)
          dp[i][k] = min(dp[i][k],max(dp[j-1][k-1],dp[i-j][k])+1);
    printf("%d\n",dp[n][m]);
  }
  return 0;
}
