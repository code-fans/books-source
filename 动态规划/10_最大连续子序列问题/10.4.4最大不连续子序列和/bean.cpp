//������������к�
//��ͬһ�����棬���ڵ����ֲ���ͬʱȡ����ôÿһ�ж��л���һ�����ֵ��
//��ô���԰�ÿһ�����ֵ����һ�����֣�����һ�Σ��൱����һ��������
//������������еĺͣ�ֻ�������ÿһ��������ÿһ�е����ֵ��
//dp[i]=max(dp[i-2]+a[i],dp[i-1])
//dp[i]����iʱ����������еĺͣ�����ÿһ�����֣�ֻ��ȡ���߲�ȡ����
//״̬�����ȡ����ô���ֵ�Ǵ�dp[i-2]�ټ��ϱ������ֵ�������ȡ����ô
//���ֵ��dp[i-1]
#include <bits/stdc++.h>
using namespace std;

int a[200005],dp[200005];

int main()
{
  //freopen("bean.in","r",stdin);
  //freopen("bean.out","w",stdout);
  int n,m;
  while(scanf("%d %d",&n,&m)==2)
  {
    for(int i=1; i<=n; i++)            //�Ȱ���DP,���ÿ����ȡ�������ֵ
    {
      for(int j=1; j<=m; j++)
        scanf("%d",&a[j]);
      for(int j=2; j<=m; j++)
        a[j]=max(a[j-1],a[j-2]+a[j]);
      dp[i]=a[m];                      //��i����ȡ�������ֵ
    }
    for(int i=2; i<=n; i++)            //�ٰ���dp,ԭ������
      dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
    printf("%d\n",dp[n]);
  }
  return 0;
}
