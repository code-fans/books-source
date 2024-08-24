//数的划分 - 递推算法2
#include<bits/stdc++.h>
using namespace std;

int N,K;
int f[205][10];

int main()
{
  cin>>N>>K;
  f[0][0]=1;
  for(int t=1; t<=N; t++)   //分出来一块为t
    for(int n=t; n<=N; n++)
      for(int k=1; k<=K; k++)
        f[n][k]+=f[n-t][k-1];
  cout<<f[N][K]<<endl;
  return 0;
}

