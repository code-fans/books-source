//丝绸之路 — DP3
#include<bits/stdc++.h>
using namespace std;

int f[1002],d[1002];

int main()
{
  //freopen("silk.in","r",stdin);
  //freopen("silk.out","w",stdout);
  memset(f,127/2,sizeof(f));
  f[0]=0;					       //到达第0个城市的最小花费为0
  int N,M;
  cin>>N>>M;
  for(int i=1; i<=N; i++)
    cin>>d[i];
  for(int i=1,c; i<=M; i++)        //先枚举天数，因为第i天可能有多个城市选择
  {
    cin>>c;
    for(int j=min(i,N); j>=1; j--) //在第i天最多能走到的城市为min(i,N)
      f[j]=min(f[j],f[j-1]+d[j]*c);
  }
  cout<<f[N]<<endl;
  return 0;
}
