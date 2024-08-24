//4
//3 19 10 6
//看样例：3 10 19 6 等价于 3 10
//这是因为 19=10+3+3+3，6=3+3.
//看起来我们要把 能够被其他钱凑出来的钱 给筛掉，
//观察样例，显然3可以把6代替，这样就转换成如果这个数可以被
//比他小的数凑出来这个数的就会被替代
//我们考虑排序（因为大的一定凑不出小的，而小的有可能凑出大的)然后求完全背包即可
#include <bits/stdc++.h>
using namespace std;
int dp[25100],f[200];

int main()
{
  //freopen("money.in","r",stdin);
  //freopen("money.out","w",stdout);
  int T;
  for(scanf("%d",&T); T; T--)
  {
    memset(dp,0,sizeof(dp));
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
      scanf("%d",&f[i]);
    sort(f+1,f+1+n);               //排序
    dp[0]=1;                       //0一定可以被表示，这是边界
    for(int i=1; i<=n; i++)        //枚举n个货币
    {
      if(dp[f[i]]==0)              //对于这个货币不能被表示
        ans++;                     //选它
      for(int j=f[i]; j<=f[n]; j++)//枚举背包容量
        dp[j]=dp[j] | dp[j-f[i]];  //无论j和j-f[i]两个哪个可以被表示，j都能被表示
    }
    printf("%d\n",ans);
  }
  return 0;
}

