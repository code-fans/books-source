//�������� - DP
#include<bits/stdc++.h>
using namespace std;

int dp[10][3],a[15];

void Init()
{
  dp[0][0]=1;
  for(int i=1; i<=8; i++)
  {
    dp[i][0]=dp[i-1][0]*9-dp[i-1][1];          //��9����Ϊ������4
    dp[i][1]=dp[i-1][0];
    dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
  }
}

int Dp(int n)
{
  int len=0;
  for(int num=n; num; num/=10)
    a[++len]=num%10;
  a[len+1]=0;
  int flag=0,unluck=0;
  for(int i=len; i>=1; i--)        //ͳ�Ʋ��������� 
  {
    unluck+=a[i]*dp[i-1][2];       //��4��62�� 
    if(flag)                       //�Ѿ���4��62 
      unluck+=a[i]*dp[i-1][0];     //�ۼӼ������� 
    else
    {
      if(a[i]>4)
        unluck+=dp[i-1][0];        //��ǰλ����ȡ4 
      if(a[i]>6)                   //iλȡ6��i-1λȡ2 
        unluck+=dp[i-1][1];
      if(a[i+1]==6 && a[i]>2)      //i+1λȡ6��iλȡ2 
        unluck+=dp[i][1];
    }
    if(a[i]==4 || (a[i+1]==6 && a[i]==2))
      flag=1;
  }
  return n-unluck;
}

int main()
{
  freopen("lucky.in","r",stdin);
  freopen("lucky.out","w",stdout);
  Init();
  for(int n,m; cin>>n && cin>>m && n+m!=0;)
    cout<<Dp(m+1)-Dp(n)<<endl;
  return 0;
}

