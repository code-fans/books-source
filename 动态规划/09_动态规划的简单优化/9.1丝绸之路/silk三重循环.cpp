//丝绸之路 —DP1
#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;

int D[1002],C[1002],f[1002][1002];

int main()
{
  int N,M;
  scanf("%d%d",&N,&M);
  for(int i=1; i<=N; i++)
    scanf("%d",&D[i]);
  for(int i=1; i<=M; i++)
  {
    scanf("%d",&C[i]);
    f[1][i]=D[1]*C[i];//初始化第一个城市的
  }
  for(int i=2; i<=N; i++) //从第2个城市开始
    for(int j=i; j<=M-(N-i); j++) //到i城市至少要在第i天,最晚不超过第M-(N-i)天
    {
      int Min=INF;
      for(int k=j-1; k>=i-1; k--)
        Min=min(Min,f[i-1][k]);
      f[i][j]=Min+D[i]*C[j];//最后再加D[i]*C[j]，以优化时间
    }
  int ans=INF;
  for(int i=N; i<=M; i++)
    ans=min(ans,f[N][i]);
  printf("%d",ans);
  return 0;
}
