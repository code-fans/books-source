//对抗赛
#include<bits/stdc++.h>
using namespace std;
int v[110];
bool dp[110][10000];

int main()
{
  //freopen("match.in","r",stdin);
  //freopen("match.out","w",stdout);
  int N,sum=0;
  cin>>N;
  int M=N>>1;
  for(int i=1; i<=N; i++)
  {
    cin>>v[i];
    sum+=v[i];
  }
  int V=sum>>1;
  dp[0][0]=true;
  for(int i=1; i<=N; i++)     //二维费用背包
    for(int j=M; j>=1; j--)
      for(int k=V; k>=v[i]; k--)
        dp[j][k]=(dp[j][k] || dp[j-1][k-v[i]]);
  for(int i=V; i>=0; i--)
    if(dp[M][i])
    {
      cout<<i<<endl;  //找出人数为N/2下能达到的最大不超过一半的分数
      break;
    }
  return 0;
}
