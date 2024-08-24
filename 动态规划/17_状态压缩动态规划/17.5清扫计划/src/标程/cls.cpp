//清扫计划
#include <bits/stdc++.h>
using namespace std;
#define INF (1<<30)

int dis[12][12],dp[1<<11][12];

int main()
{
  freopen("cls.in","r",stdin);
  freopen("cls.out","w",stdout);
  int n;
  while(scanf("%d",&n) && n)
  {
    for(int i=0; i<=n; ++i)
      for(int j=0; j<=n; ++j)
        scanf("%d",&dis[i][j]);
    for(int k=0; k<=n; ++k)                //Floyd算法
      for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
          if(dis[i][k]+dis[k][j]<dis[i][j])
            dis[i][j]=dis[i][k]+dis[k][j];
    for(int S=0; S<=(1<<n)-1; ++S)         //枚举所有状态，位运算表示
      for(int i=1; i<=n; ++i)              //枚举n个城市
        if(S & (1<<(i-1)))                 //状态S中已经经过城市i
          if(S==(1<<(i-1)))                //状态S只经过城市i
            dp[S][i]=dis[0][i];            //最优解自然是dis[0][i]
          else                             //如果S有经过多个城市
          {
            dp[S][i]=INF;
            for(int j=1; j<=n; ++j)       //寻找j使得距离更短,和floyd一样
              if(S & (1<<(j-1)) && j!=i)  //j已到达过且j不等于i
                dp[S][i]=min(dp[S^(1<<(i-1))][j]+dis[j][i],dp[S][i]);
          }
    int ans=dp[(1<<n)-1][1]+dis[1][0];
    for(int i=2; i<=n; ++i)               //找到最优解
      ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
    printf("%d\n",ans);
  }
  return 0;
}

