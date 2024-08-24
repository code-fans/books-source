//���ּ��� ��DFS
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL l,r,dp[20][20],num[20];

LL DFS(int pos, int x,LL sum, bool lead, bool limit)
{
  if (pos==0)
    return sum;
  if (!lead && !limit && dp[pos][sum]!=-1)
    return dp[pos][sum];
  LL ans=0;
  int up=limit ? num[pos] : 9;  //��ǰ��λ���ֵ
  for (int i=0; i<=up; ++i)     //�����iλ����������Ҫ������룬�Ҹ����벻��ǰ���㣬��+1
    ans+=DFS(pos-1, x,sum+((i==x) && !(lead && !i)), lead & !i, limit & i==up);
  if (!lead & !limit)
    dp[pos][sum]=ans;           //��¼��״̬��ֵ
  return ans;
}

LL Cal(LL x, int digit)
{
  int len=0;
  for (; x; x/=10)
    num[++len]=x%10;
  memset(dp,-1,sizeof(dp));     //ÿһ�ζ�Ҫ��ʼ��
  return DFS(len,digit,0,1,1);  //ע���һλ����ǰ��������λ������
}

int main()
{
  //freopen("count.in","r",stdin);
  //freopen("count.out","w",stdout);
  cin>>l>>r;
  for(int i=0; i<=9; i++)
    printf("%lld%c",Cal(r,i)-Cal(l-1,i),i==9?'\n':' ');
  return 0;
}
