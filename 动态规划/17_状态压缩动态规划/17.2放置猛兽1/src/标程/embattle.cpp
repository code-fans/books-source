//放置猛兽1
#include<bits/stdc++.h>
using namespace std;

long long F[11][155][155];      //F[i][a][k]:第i行在a状态下放k只猛兽的方案数
int num[155],s[155],N,K,states; //states表示一行中,可能放置的合法状态数

void Init()
{
  for(int i=0; i<(1<<N); ++i)   //枚举000…000~111…111的所有可能状态
  {
    if(i&(i<<1))                //如行内互相攻击则此状态丢弃
      continue;
    s[++states]=i;              //保存这个合法的状态
    for(int t=i; t; t>>=1)
      num[states]+=(t&1);       //统计该合法状态下放置的猛兽数
  }
}

void DP()
{
  F[0][1][0]=1;                 //注意程序的states下标是从1开始的
  for(int i=1; i<=N; ++i)       //枚举行
    for(int a=1; a<=states; ++a)//枚举上一行状态
      for(int k=num[a]; k<=K; ++k)//枚举放置的猛兽数
        for(int b=1; b<=states; ++b) //枚举该行的状态
          if(!(s[a]&s[b]) && !(s[a]&(s[b]<<1))&& !(s[b]&(s[a]<<1)))
            F[i][a][k]+=F[i-1][b][k-num[a]];//无冲突则累加方案数
  long long ans=0;
  for(int i=1; i<=states; ++i)
    ans+=F[N][i][K];
  cout<<ans<<endl;
}

int main()
{
  //freopen("embattle.in","r",stdin);
  //freopen("embattle.out","w",stdout);
  cin>>N>>K;
  Init();
  DP();
  return 0;
}

