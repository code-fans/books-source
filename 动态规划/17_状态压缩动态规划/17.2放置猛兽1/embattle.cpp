//猛兽军团1
#include<bits/stdc++.h>
using namespace std;

long long F[11][155][155];      //f[i][a][k]:第i行在a状态下放k只猛兽的方案数
int num[155],s[155],N,K,states; //states表示一行中,可能放置的合法状态数

void Init()
{
  for(int i=0; i<(1<<N); ++i)   //枚举000…000~111…111的所有可能状态
  {
    if(i&(i<<1))                //如行内互相攻击则此状态丢弃
      continue;
    int k=0;
    for(int j=0; j<N; ++j)      //统计该合法状态下放置的猛兽数
      if(i&(1<<j))
        ++k;
    s[++states]=i;              //保存该合法状态,和上文算法分析不同,下标从1开始
    num[states]=k;              //保存该合法状态下放置的猛兽数
  }
}

void DP()
{
  F[0][1][0]=1;                 //注意程序的states下标是从1开始的
  for(int i=1; i<=N; ++i)       //枚举行
    for(int j=1; j<=states; ++j)//枚举状态
      for(int kk=0; kk<=K; ++kk)//枚举放置的猛兽数
        if(kk>=num[j])          //如果不超过限制的猛兽数
          for(int t=1; t<=states; ++t) //枚举上一行的状态
            if(!(s[t]&s[j]) && !(s[t]&(s[j]<<1))&& !(s[t]&(s[j]>>1)))//无冲突
              F[i][j][kk]+=F[i-1][t][kk-num[j]];
}

void Out(long long ans=0)
{
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
  Out();
  return 0;
}

