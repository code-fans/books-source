//�۲�17��18��20�Ķ����Ʊ�ʾ�����Է��֣�����K��1����Ϊ�����ݸ�����ͬ
//�ƹ㵽B���ƣ�������������ת��ΪB���ƣ�ͬ����K��1
//��Ŀת������ĳ�����ڣ�����һ������b������ǡ����k��1�����඼��0�����ĸ����ж��ٸ�
//b����Ҳ��2�������㣬����0������������1��0��Ϊ0����
#include<bits/stdc++.h>
using namespace std;

int x,y,k,b;
int a[34];
int dp[34][34];

int DFS(int pos, int sum, bool limit)
{
  if(pos<=0 || sum>k)
    return sum==k;
  if(!limit && dp[pos][sum]!=-1)
    return dp[pos][sum];
  int up=limit?(a[pos]?1:0):1;
  int ans=0;
  for(int i=0; i<=up; i++)
    ans+=DFS(pos-1,sum+i,limit && i==a[pos]);
  if(!limit)
    dp[pos][sum]=ans;
  return ans;
}

int Cal(int n)
{
  int len=0;
  for(; n; n/=b)//ת��B���� 
    a[++len]=n%b;
  return DFS(len,0,true);
}

int main()
{
  freopen("amount.in","r",stdin);
  freopen("amount.out","w",stdout);
  memset(dp,-1,sizeof(dp));
  scanf("%d%d%d%d",&x,&y,&k,&b);
  printf("%d\n",Cal(y)-Cal(x-1));
}

