//���ַ���
//����Щ�������ֵΪMax,���ǵĺ�Ϊsum,��������һ�ѵ�ֵΪ��Max+sum)/2;
//�������ת�����˰�����ת��Ϊ��n����Ʒ��ȡ���ɸ���ʹ��������������max1+sum)/2���������ﵽ���
//���Ϊsum�������Ϊmax����������ʱ������ĺͷֱ��ǣ�sum��max)/2 �� ��sum��max)/2��
//�����Ļ����κ�һ�鱳����ֵ���ڣ�sum��max)/2 ~��sum��max)/2֮�䣬�Ϳ���ת����
//��������һ���ݻ�Ϊ��sum��max)/2 �İ�������ֵһ������ sum/2��
#include<bits/stdc++.h>
using namespace std;

int a[maxn],dp[maxn];
int n,sum,Max;

int main()
{
  //freopen("Stone2.in","r",stdin);
  //freopen("Stone2.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    sum+=a[i];
    Max=max(Max,a[i]);
  }
  int t=(max1+sum)/2;
  for(int i=1; i<=n; i++)
    for(int j=t; j>=a[i]; j--)
      dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
  printf("%d\n",abs(sum-dp[t]-dp[t]));
  return 0;
}
