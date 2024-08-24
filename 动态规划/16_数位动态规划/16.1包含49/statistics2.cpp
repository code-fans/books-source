//包含49 - DP
#include <bits/stdc++.h>
using namespace std;

long long n,dp[22][3];
int a[22];

void Init()
{
  dp[0][0]=1;
  for(int i=1; i<=21; i++)
  {
    dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
    dp[i][1]=dp[i-1][0];
    dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
  }
}

long long Cal(long long n,int len)
{
  long long ans=0;
  bool flag=false;
  for(int i=len; i>=1; i--)  //从高位向低位扫描
  {
    ans+=dp[i-1][2]*a[i];
    if(flag)
      ans+=(dp[i-1][0])*a[i];
    else if(!flag && a[i]>4)
      ans+=dp[i-1][1];
    if(a[i+1]==4 && a[i]==9)
      flag=true;
  }
  if(flag)
    ans++;
  return ans;
}

int main()
{
  freopen("statistics.in","r",stdin);
  freopen("statistics.out","w",stdout);
  Init();
  int t,len;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(len=0; n; n/=10)
      a[++len]=n%10;
    a[len+1]=0;
    cout<<Cal(n,len)<<endl;
  }
  return 0;
}

