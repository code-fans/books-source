//����
//��Ϊ������1000�ı��������԰�m�ͻ���Ļ���
//����С1000ȥ���б�����⣬�õ��Ľ���δ��С��
//��Ǯ��ȥ�ӣ�Ȼ������С1000ȥ�����һ��ġ�
//������1000��������Ҳ����Ӱ����
#include <bits/stdc++.h>
using namespace std;

int T,amount,n,d;
int weight[12],profit[12],dp[1000002];

int main()
{
  freopen("Profit.in","r",stdin);
  freopen("Profit.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&amount,&n,&d);
    for (int i=0; i<d; i++)
    {
      scanf("%d%d",&weight[i],&profit[i]);
      weight[i] /= 1000;
    }
    for (int i=0; i<n; i++)              //ö��ÿһ��
    {
      int t = amount/1000;
      for (int j=0; j<d; j++)            //ö��ÿһ��ծȯ
        for (int k=weight[j]; k<=t; k++) //ö�ٱ�����������ֵ��
          dp[k]=max(dp[k],dp[k-weight[j]]+profit[j]);
      amount += dp[t];                   //ÿ�������Ҫ�������е�Ǯ
    }
    printf("%d\n",amount);
  }
  return 0;
}

