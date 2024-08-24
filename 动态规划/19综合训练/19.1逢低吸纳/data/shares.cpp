//逢低吸纳 —高精度
//第二问，比如5 3 1 5 3 1 有两个重复，所以定义num[],num[i]表示以a[i]为结尾的LIS长度相同方案个数
//这样在扫描过程中，如果遇到LIS长度相同，且最后字符一样的，跳过不统计就可
#include<bits/stdc++.h>
using namespace std;

int n,mx;
int a[5005]= {0x7ffffff}; //a[0]=OO
int dp[5005];             //dp[0]==0
string num[5005]= {"1"};  //num[0]=1  num[i]:以a[i]为结尾的LIS长度相同方案个数

string Add(string a,string b)
{
  string ans(max(a.size(),b.size())+1,'0');//设ans的长度，并全部填充0
  for(int i=ans.size()-1,l1=a.size(),l2=b.size(); i>=0; i--)//倒序相加
  {
    int t=(ans[i]-'0')+(l1<1?0:a[--l1]-'0')+(l2<1?0:b[--l2]-'0');//转成数字逐位相加
    ans[i]=t%10+'0';//余数转为字符保存
    ans[i-1]=(ans[i-1]-'0'+t/10)+'0';//进位
  }
  for(; ans[0]=='0' && ans.size()>1; ans.erase(0,1));//删除前导0
  return ans;
}

int main()
{
  freopen("shares.in","r",stdin);
  freopen("shares.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  for(int i=1; i<=n; i++)
  {
    for(int j=i-1; j>=0; j--)            //找最长子序列
      if(a[j]>a[i] && dp[i]<=dp[j])
        dp[i]=dp[j]+1;
    for(int j=i-1; j>=0; j--)
    {
      if(a[j]>a[i] && dp[j]+1==dp[i])    //如果前面的的子串可以连上当前的a[i]且不一样则相加
        num[i]=Add(num[i],num[j]);       //则以a[i]结尾，相同长度的方案数统计到num[i]中
      else if(a[i]==a[j] && dp[i]==dp[j])//如果一样的就停止，则停止统计，以免重复
        break;                           //后面不可能再有连接了
    }
  }
  string nums="0";
  for(int i=1; i<=n; i++)
    if(mx<dp[i])
    {
      mx=dp[i];
      nums=num[i];
    }
    else if(mx==dp[i])
      nums=Add(nums,num[i]);
  cout<<mx<<" "<<nums<<endl;
  return 0;
}
