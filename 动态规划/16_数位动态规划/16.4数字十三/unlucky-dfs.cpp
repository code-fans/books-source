//����ʮ��
//��ĿҪ�����13���ܱ�13���������Զ���
//dp[pos][last][ok][mod]��ʾposλ������λ����last,ok:�Ƿ��Ѿ�����13��mod:������13ȡģ���ֵ
#include <bits/stdc++.h>
using namespace std;

const int N=20;
int dp[N][10][2][13],num[N],n,len;

int DFS(int pos,int last,bool ok,int mod,bool limit)//��һλ��,��ǰ��������
{
  if (!pos)
    return ok && !mod;    //����13���ܱ�13����������1
  if (~dp[pos][last][ok][mod] && !limit)//���dp[pos][last][ok][mod]�Ѿ���ֵ��������
    return dp[pos][last][ok][mod];
  int up=limit ? num[pos]:9;
  int ans=0;
  for (int i=0; i<=up; i++)
    ans+=DFS(pos-1,i,ok || last==1 && i==3,(mod*10+i)%13,limit && i==num[pos]);
  if (!limit)
    dp[pos][last][ok][mod]=ans;
  return ans;
}

int main()
{
  freopen("unlucky.in","r",stdin);
  freopen("unlucky.out","w",stdout);
  memset(dp,-1,sizeof(dp));
  while (~scanf("%d",&n))            //û�����뷵��-1,ȡ��Ϊ0
  {
    for(len=0; n; n/=10)
      num[++len]=n%10;
    printf("%d\n",DFS(len,0,0,0,1));
  }
  return 0;
}
