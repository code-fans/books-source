//均分魔法石
//质量和为奇显然不能，偶数时只要达到sum/2的背包就行了，
//剩下的自然组成了另外sum/2的背包。
//已知正常多重背包复杂度为O((ΣN[i])V),这里(ΣN[i])<=120000,V<=60000;
//如果直接进行多重背包肯定超时。所以我们用二进制优化的多重背包。
#include <bits/stdc++.h>
using namespace std;

int num[7],dp[60010];
int dig[]= {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

int main()
{
  //freopen("dividing.in","r",stdin);
  //freopen("dividing.out","w",stdout);
  for(int ncase=1; ; ncase++)
  {
    int  sum = 0;
    for(int i=1; i<=6; i++)
    {
      scanf("%d",&num[i]);
      sum += i*num[i];
    }
    if(sum == 0)
      break;
    printf("Collection #%d:\n",ncase);
    if(sum&1)
    {
      printf("Can't be divided.\n\n");
      continue;
    }
    memset(dp,0,sizeof(dp));
    sum/=2;
    for(int i=1,v; i<=6; i++)
      for(int d=0; num[i]; d++)
      {
        if(num[i] >= dig[d])
        {
          v = i*dig[d];
          num[i] -= dig[d];
        }
        else
        {
          v = i*num[i];
          num[i] = 0;
        }
        for(int j=sum; j>=v; j--)
          dp[j] = max(dp[j],dp[j-v]+v);
      }
    if(dp[sum] == sum)
      printf("Can be divided.\n\n");
    else
      printf("Can't be divided.\n\n");
  }
  return 0;
}
