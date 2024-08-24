#include<bits/stdc++.h>
using namespace std;
const int MAXN=65537;

string str;
int dp[MAXN],cycle[MAXN],tot;//cycle是处理出来的回文子序列，tot记录个数

bool Check(int x)                //判断x状态是否为回文
{
  char t[MAXN];
  int cnt=0,len=str.length();
  for(int i=0; i<len; i++)
    if(x>>i&1)
      t[cnt++]=str[len-i-1];
  for(int l=0,r=cnt-1; l<r; ++l,--r)
    if(t[l]!=t[r])
      return 0;
  return 1;
}

int main()
{
  //freopen("palindrome.in","r",stdin);
  //freopen("palindrome.out","w",stdout);
  int N;
  cin>>N;
  while(N--)
  {
    tot=0;                         //tot为找到的回文数个数
    memset(dp,0x3F,sizeof(dp));
    cin>>str;
    int maxx=(1<<str.length())-1;
    for(int i=1; i<=maxx; i++)
      if(Check(i))
      {
        dp[i]=1;
        cycle[++tot]=i;               //保存找到的回文串
      }
    for(int i=1; i<=maxx; i++)        //枚举所有状态
      for(int j=1; j<=tot; j++)       //枚举所有回文数
        if((i&cycle[j])==0)           //如果i不在当前状态中
          dp[i|cycle[j]]=min(dp[i|cycle[j]],dp[i]+1);//i的状态加cycle[j]就是dp[i]+1
    cout<<dp[maxx]<<endl;
  }
  return 0;
}

//用二进制来表示一个数是否已经删去，1为删去，0为未删
//dp[s]表示在s（转化为二进制）的情况下，最少需要几步
//预处理把所有回文子序列记录下来，可把对应的dp[s]改成1（回文子系列只用一次就能完成）
//我们的目标是从0变成1111.....
//字符串长度为len的话
//我们要的目标状态就是1<<len-1（位运算）
//如长度为4，目标为10000-1=1111
//遍历0到1<<len-1，把这个状态和预处理出来的状态合并，得到新的状态,新状态的步数就等于原状态+1
//dp[i]表示到状态i最少步数
//DFS也可以
