//�����Ƶ����ּ��� POJ 3252
//��ɶ����ƣ�������ǰ��0
//dp[l][i][j]������Ϊl,ǰ��i��0��j��1������£�����������õ��ķ����������ܸ���
//��1001,1010  �ܸ���Ҳ��һ����
#include <bits/stdc++.h>
using namespace std;

int l,r;
int digit[35];
int dp[35][35][35];

int DFS( int pos,int sum0,int sum1,bool limit,bool lead)//ǰ��0
{
  if (pos==0)
    return sum0>=sum1;
  if (!limit && dp[pos][sum0][sum1]!=-1)
    return dp[pos][sum0][sum1];
  int up=limit?digit[pos]:1;
  int ans=0;
  if (lead)//���û��ǰ��0
    for (int i=0; i<=up; i++)
      ans+=DFS(pos-1,sum0+(i==0), sum1+(i==1),limit&&i==up,true);
  else
    for ( int i=0; i<=up; i++)
      if (i==0)
        ans+=DFS(pos-1,0,0,limit&&i==up,false);
      else
        ans+=DFS(pos-1,0,1,limit&&i==up,true);
  if (!limit)
    dp[pos][sum0][sum1]=ans;
  return ans;
}

int Cal(int n)
{
  int len=0 ;
  for(; n; n/=2)
    digit[++len]=n%2;
  return DFS(len,0,0,true,false);
}

int main()
{
  //freopen("round.in","r",stdin);
  //freopen("round.out","w",stdout);
  memset(dp,-1,sizeof(dp));
  cin>>l>>r;
  int ans=Cal(r)-Cal(l-1 );
  cout<<ans<<endl;
  return 0;
}

