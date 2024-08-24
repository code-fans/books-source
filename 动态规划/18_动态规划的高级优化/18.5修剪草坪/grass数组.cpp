//f[i]代表选择第i个员工，能获得的最大值。
//则 f[i] = max(f[i],f[j]+sum[i]-sum[j+1]);
//可以发现sum[i]是不变的，只要求f[j]-sum[j+1]的最大值就可以了
//这个就可以用单调队列来优化
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;

long long f[N],sum[N],ans;
int a[N],n,m,k,q[N];

int main()
{
  //freopen("grass.in","r",stdin);
  //freopen("grass.out","w",stdout);
  scanf("%d%d",&n,&k);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d",&a[i]);
    sum[i] = sum[i-1] + a[i];
  }
  int l=0, r=0;               //队列的左边界和右边界 
  for (int i = 1; i <= n; ++i)
  {
    if (q[l] < i-k-1)         //维护区间宽度 
      l++;
    if (i<=k)                 //当前人的编号还不够k 
      f[i]=sum[i];
    else
      f[i]=max(f[i],f[q[l]]-sum[q[l]+1]+sum[i]);
    while(l<=r && (f[i]-sum[i+1]>=f[q[r]]-sum[q[r]+1]))
      r--;                    //维护单调性 
    q[++r]=i;
    ans=max(ans,f[i]);
  }
  printf("%lld\n",ans);
  return 0;
}
