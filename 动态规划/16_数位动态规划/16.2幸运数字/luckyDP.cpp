//�������� - DFS
#include<bits/stdc++.h>
using namespace std;

int dp[8][2],digit[8];

int DFS(int len,bool six,bool limit)    //�ڶ���������ʾ��һλ�ǲ���6
{
  if(!len)
    return 1;
  if(!limit && dp[len][six]!=-1)        //�����Ʋ���dp[][]�б���ֵ
    return dp[len][six];
  int ans=0;
  int up=limit ? digit[len]:9;
  for(int i=0; i<=up; i++)
  {
    if(i==4 || six && i==2)             //������������������
      continue;
    ans+=DFS(len-1,i==6,limit && i==up);
  }
  if(!limit)
    dp[len][six] = ans;
  return ans;
}

int Cal(int n)
{
  int len=0;
  for(; n; n/=10)
    digit[++len]=n%10;
  return DFS(len,false,true);
}

int main()
{
  freopen("lucky.in","r",stdin);
  freopen("lucky.out","w",stdout);
  memset(dp,-1,sizeof(dp));             //ֻ���ʼ��һ��
  for(int m,n; scanf("%d%d",&n,&m),n|m;)
    printf("%d\n",Cal(m)-Cal(n-1));
  return 0;
}

