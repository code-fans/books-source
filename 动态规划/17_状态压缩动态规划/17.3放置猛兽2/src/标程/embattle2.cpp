//放置猛兽2
#include <bits/stdc++.h>
using namespace std;
#define MOD 100000000

int M,N,row[13];
int put[13][1000];
int F[13][1000],Ans=0;

void Init()
{
  cin>>M>>N;
  for(int x,i=1; i<=M; i++)
    for(int j=1; j<=N; j++)                   //压缩每行能否放置的状态
    {
      cin>>x;
      row[i]=(row[i]<<1)+1-x;
    }
  for(int i=1; i<=M; i++)                     //获得每一行所有可行状态
    for(int j=0; j<(1<<N); j++)
    {
      if((j<<1)&j || (j>>1)&j || j&row[i])   //冲突则忽略
        continue;
      put[i][0]++;                            //保存i行能放置的状态数
      put[i][put[i][0]]=j;                    //保存该状态
    }
}

void Dp()
{
  F[0][1]=1;
  put[0][0]=1;                                //初始值,第零行都不放置
  for(int i=1; i<=M; i++)                     //枚举行
    for(int b=1; b<=put[i-1][0]; b++)         //枚举上一行的状态
      for(int a=1; a<=put[i][0]; a++)         //枚举此行状态
      {
        if(put[i-1][b] & put[i][a])
          continue;                           //产生冲突
        F[i][a]+=F[i-1][b];
        F[i][a]%=MOD;                         //防止溢出
      }
  for(int i=1; i<=put[M][0]; i++)             //统计最后一行
    Ans+=F[M][i],Ans%=MOD;
  cout<<Ans<<endl;
}

int main()
{
  freopen("embattle2.in","r",stdin);
  freopen("embattle2.out","w",stdout);
  Init();
  Dp();
  return 0;
}

