//ȡ���-�򵥵Ķ��ر���
#include <bits/stdc++.h>
using namespace std;

int w[110],dp[100010];                //dp[j]��ʾcashΪjʱ�ܵõ��������

int main()
{
  //freopen("cash.in","r",stdin);
  //freopen("cash.out","w",stdout);
  int cash,N,n,d;
  while(scanf("%d%d",&cash,&N)!=EOF)
  {
    memset(dp,0,sizeof(dp));
    int count = 1;
    for(int i=1; i<=N; i++)
    {
      scanf("%d%d",&n,&d);
      for(int j=1; j<=n; j<<=1)       //j����һλ�����ж����Ʋ��
      {
        w[count++]=j*d;               //��ֵ������Ӧ�Ķ�����ϵ��
        n-=j;
      }
      if(n>0)                         //ʣ��δ��ֵ�
        w[count++]=n*d;
    }
    for(int i=1; i<count; i++)        //תΪ01����
      for(int j=cash; j>=w[i]; j--)
        dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
    printf("%d\n",dp[cash]);
  }
  return 0;
}

