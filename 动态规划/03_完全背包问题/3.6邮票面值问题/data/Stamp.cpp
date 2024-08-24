#include <bits/stdc++.h>
using namespace std;
const int MAXN=51;

int n,k,f[MAXN]= {0,1},stamp[MAXN],MAX;

void Dfs(int idx)
{
  if(idx>k)                               //所有邮票都试完了
  {
    int dp[5100]= {0};
    int i=0;
    while(dp[i]<=n)                       //如果之前的邮票数超过n，不可行,就没必要继续了
    {
      i++;                                //下个位置
      dp[i]=0x3f3f3f3f;                   //dp[i]表示已知面值的邮票组合出面值为i所需要的最小邮票数
      for(int j=1; j<=k && i-f[j]>=0; j++)//枚举k种邮票,并且可以尝试这种邮票
        dp[i]=min(dp[i],dp[i-f[j]]+1);
    }
    if(i-1>MAX)
    {
      memcpy(stamp,f,sizeof(f));          //复制当前的最优解
      MAX=i-1;
    }
    return;
  }
  for(int i=f[idx-1]+1; i<=f[idx-1]*n+1; i++)
  {
    f[idx]=i;                               //尝试另一个面值
    Dfs(idx+1);
  }
}

int main()
{
  scanf("%d%d",&n,&k);
  Dfs(2);                                   //第一张邮票是1,从第二张邮票开始
  for(int i=1; i<=k; i++)
    printf("%d ",stamp[i]);
  printf("\nMAX=%d\n",MAX);
  return 0;
}
//提问1
//以n=3,k=3为例:第一个面值肯定为1，但是第二个面值只能是2，3，4，因为面值为1的最多贴3张
//贴满的最大值为3，要保证数字连续,那么第二个数字最大是4
//所以我们可以得到规律，如果邮票张数为n，种类为k,那么从小到大的顺序，邮票a[i]的下一种面值的取值范围必然是f[i]+1到f[i]*n+1
