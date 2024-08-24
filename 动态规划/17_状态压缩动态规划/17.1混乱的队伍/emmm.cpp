//混乱的队伍
#include <bits/stdc++.h>
using namespace std;

int N,K;
int a[17];
long long dp[16][1<<16];

int main()
{
  freopen("emmm.in","r",stdin);
  freopen("emmm.out","w",stdout);
  scanf("%d%d",&N,&K);
  for(int i=0; i<N; i++)
    scanf("%d",&a[i]);
  for(int i=0; i<N; i++)
    dp[i][1<<i]=1;                               //初始只有一只奶牛的方案数为1
  for(int state=0; state<(1<<N); state++)        //枚举所有状态
    for(int j=0; j<N; j++)                       //枚举末尾可能的奶牛
      if(state & (1<<j))                         //如果该奶牛存在于此状态中
        for(int i=0; i<N; i++)                   //枚举末尾要加入的奶牛i
          if(!(state&(1<<i)) && abs(a[j]-a[i])>K)//如果该奶牛之前没有放并且可放
            dp[i][state|(1<<i)]+=dp[j][state];   //则更新奶牛k为末尾的方案数
  long long ans=0;
  for (int i=0; i<N; i++)
    ans+=dp[i][(1<<N)-1];                        //累加混乱的方案数
  printf("%lld\n",ans);
  return 0;
}
