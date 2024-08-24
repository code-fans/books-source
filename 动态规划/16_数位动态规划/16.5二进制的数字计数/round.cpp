#include <bits/stdc++.h>
using namespace std;

int c[33][33];

void Init()//组合数打表
{
  c[0][0]=1;
  for(int i=1; i<33; i++)
  {
    c[i][0]=1;
    for(int j=1; j<=i; j++)
      c[i][j]=c[i-1][j]+c[i-1][j-1];
  }
}

int Count(int n)              //寻找比n小符合条件个数
{
  int len=0,zero=0,ans=0;
  bool m[33]= {0};
  for(; n; n>>=1)             // 转化为二进制保存到m[]
    m[++len]=n%2;
  for(int i=2; i<len; i++) //计算二进制位数小于len的情况，位数为1不满足条件 
    for(int j=(i+1)/2; j<i; j++)//枚举取0的个数 
      ans+=c[i-1][j];
  for(int i=len-1; i>=1; i--) //计算二进制位数等于len的情况
    if(m[i])                 //如果当前位是1 
      for(int j=(len+1)/2-(zero+1); j<i; j++) //遍历每种小于的情况
        ans+=c[i-1][j];
    else                     //如果当前位是0,直接zero+1 
      zero++;
  return ans;
}

int main()
{
  //freopen("round.in","r",stdin);
  //freopen("round.out","w",stdout);
  int s,e;
  Init();
  while(cin>>s>>e)
    cout<<Count(e+1)-Count(s)<<endl;
  return 0;
}
