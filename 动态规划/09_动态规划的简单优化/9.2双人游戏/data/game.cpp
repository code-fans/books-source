//˫����Ϸ �������㷨��
#include<bits/stdc++.h>
using namespace std;

int dp[5001],sum[5001];

int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>dp[i];                       //�൱��dp[i][i]
    sum[i]=sum[i-1]+dp[i];                    //ǰ׺��
  }
  for(int l=2; l<=n; l++)                     //���������
    for(int i=1; i<=n-l+1; i++)
      dp[i]=sum[i+l-1]-sum[i-1]-min(dp[i+1],dp[i]);
  cout<<dp[1]<<' '<<sum[n]-dp[1]<<endl;
  return 0;
}
