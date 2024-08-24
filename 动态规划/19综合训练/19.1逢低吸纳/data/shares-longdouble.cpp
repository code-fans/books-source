//逢低吸纳 —使用了long double 代替高精度
//第二问，比如5 3 1 5 3 1 有两个重复，所以定义num[],
//num[i]表示以a[i]为结尾的LIS长度相同方案个数
//这样在扫描过程中，如果遇到LIS长度相同，且最后字符一样的，跳过不统计就可
#include<bits/stdc++.h>
using namespace std;

int n,mx;
int a[5005]= {0x7ffffff}; //a[0]=OO
int dp[5005];             //dp[0]==0
long double num[5005]= {1}; //num[0]=1  num[i]:以a[i]为结尾的LIS长度相同方案个数

int main()
{
  freopen("shares.in","r",stdin);
  freopen("shares.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  for(int i=1; i<=n; i++)
  {
    for(int j=i-1; j>=0; j--) //找最长子序列
      if(a[j]>a[i] && dp[i]<=dp[j])
        dp[i]=dp[j]+1;
    for(int j=i-1; j>=0; j--)
    {
      if(a[j]>a[i] && dp[j]+1==dp[i])//如果前面的的子串可以连上当前的a[i]且不一样则相加
        num[i]+=num[j];              //则以a[i]结尾，相同长度的方案数统计到num[i]中
      else if(a[i]==a[j] && dp[i]==dp[j])//如果一样的就停止，则停止统计，以免重复
        break;                           //后面不可能再有连接了
    }
  }
  long double nums=0;
  for(int i=1; i<=n; i++)
    if(mx<dp[i])
    {
      mx=dp[i];
      nums=num[i];
    }
    else if(mx==dp[i])
      nums+=num[i];
  cout<<mx<<" "<<setprecision(0)<<fixed<<nums<<endl;
  return 0;
}
