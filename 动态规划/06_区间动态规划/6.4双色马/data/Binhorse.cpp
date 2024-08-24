//双色马
#include <bits/stdc++.h>
using namespace std;
#define dp(i,j) dp[(i)%2][j]

int dp[2][510],b[510];

int main()
{
  //freopen("Binhorse.in","r",stdin);
  //freopen("Binhorse.out","w",stdout);
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0; i<2; i++)            //马厩数要大于等于马数
    for(int j=i+1; j<501; j++)
      dp[i][j]=1<<30;               //其它均设为无穷大
  for(int i=1,x; i<=N; i++)
  {
    scanf("%d",&x);
    b[i]=b[i-1]+x;                  //黑马的前缀和数组
  }
  for(int i=1; i<=K; i++)           //枚举马厩
    for(int j=i; j<=N-(K-i); j++)   //枚举前i个马厩放的马匹数
      for(int k=i-1; k<j; k++)      //前面的马厩分配了k匹马
        dp(i,j)=min(dp(i,j),dp(i-1,k)+(b[j]-b[k])*(j-k-(b[j]-b[k])));
  printf("%d\n",dp(K,N));
  return 0 ;
}
