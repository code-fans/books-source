//�Կ���
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
  for(int i=1; i<=N; i++)     //��ά���ñ���
    for(int j=M; j>=1; j--)
      for(int k=V; k>=v[i]; k--)
        dp[j][k]=(dp[j][k] || dp[j-1][k-v[i]]);
  for(int i=V; i>=0; i--)
    if(dp[M][i])
    {
      cout<<i<<endl;  //�ҳ�����ΪN/2���ܴﵽ����󲻳���һ��ķ���
      break;
    }
  return 0;
}
