//货币面值 -01背包
#include <bits/stdc++.h>
using namespace std;

int N,MAX;
int value[101],dp[10001];

int ZeroOnePack()
{
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= N; ++i)//枚举货币
    for (int j = MAX; j >= value[i]; --j)//枚举面值
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
      MAX += value[i];         //全部货币的和
    }
    sort(value,value+N);
    cout<<ZeroOnePack()<<endl;
  }
  return 0;
}
