//拆成二进制，不允许前导0
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL MAXN = 101;

LL l, r;
LL a[MAXN], dp[MAXN][MAXN][MAXN];

LL DFS(LL len, bool limit, LL sum0, LL sum1)     //0和1的个数初始为-1
{
  if(len == 0)
    return (sum0!=-1) && (sum1!=-1) && (sum0>=sum1);//返回符合条件的数
  if(!limit && dp[len][sum0][sum1])                 //记忆化搜索
    return dp[len][sum0][sum1];
  LL ans=0;
  int up=limit ? a[len]:1;
  for(LL i=0; i<=up; i++)
  {
    if(i==0)
      ans+=DFS(len-1, limit && (i==a[len]), sum0==-1 ? 1:sum0+1, sum1);
    else                  //sum1==-1时，sum0必须为0,否则出现了前导0 
      ans+=DFS(len-1, limit && (i==a[len]), sum1==-1?0:sum0, sum1==-1?1:sum1+1);
  }
  if(!limit)
    dp[len][sum0][sum1]=ans;           //保存计算出来的值
  return ans;
}

LL Cal(LL x)               //拆成二进制保存
{
  LL len=0;
  for(; x; x>>=1)
    a[++len]=x%2;
  return DFS(len, 1, -1, -1);
}

int main()
{
  //freopen("round.in","r",stdin);
  //freopen("round.out","w",stdout);
  cin>>l>>r;
  cout<<Cal(r)-Cal(l-1)<<endl;
  return 0;
}
