//������ֵ -01����
#include <bits/stdc++.h>
using namespace std;

int N,MAX;
int value[101],dp[10001];

int ZeroOnePack()
{
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= N; ++i)//ö�ٻ���
    for (int j = MAX; j >= value[i]; --j)//ö����ֵ
      dp[j] = max(dp[j], dp[j-value[i]] + value[i]);
  for (int i = 1; i <= MAX; ++i)
    if (dp[i] != i)
      return i;
}

int main()
{
  freopen("Currency.in","r",stdin);
  freopen("Currency.out","w",stdout);
  while (scanf("%d", &N) != EOF)
  {
    MAX = 0;
    for (int i = 1; i <= N; ++i)
    {
      scanf("%d", &value[i]);
      MAX += value[i];         //ȫ�����ҵĺ�
    }
    sort(value,value+N);
    cout<<ZeroOnePack()<<endl;
  }
  return 0;
}
