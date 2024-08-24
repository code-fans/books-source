//数字分组
//设这些数的最大值为Max,他们的和为sum,所以其中一堆的值为（Max+sum)/2;
//该问题就转化成了把问题转化为从n个物品中取若干个，使其重量不超过（max1+sum)/2，且重量达到最大
//设和为sum，最大数为max，则相差最大时，两组的和分别是（sum＋max)/2 和 （sum－max)/2，
//这样的话，任何一组背包的值都在（sum－max)/2 ~（sum＋max)/2之间，就可以转换成
//尽量填满一个容积为（sum＋max)/2 的包，最后的值一定大于 sum/2，
#include<bits/stdc++.h>
using namespace std;

int a[maxn],dp[maxn];
int n,sum,Max;

int main()
{
  //freopen("Stone2.in","r",stdin);
  //freopen("Stone2.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    sum+=a[i];
    Max=max(Max,a[i]);
  }
  int t=(max1+sum)/2;
  for(int i=1; i<=n; i++)
    for(int j=t; j>=a[i]; j--)
      dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
  printf("%d\n",abs(sum-dp[t]-dp[t]));
  return 0;
}
