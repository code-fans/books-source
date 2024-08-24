//f[i]表示以第i天为最后一天的享受值
//用sum求出前缀和，f[i]=sum[i]-min{sum[k]}(i-q<=k<=i-p)
//单调队列维护单调递增区间，每次队首取出最小值
#include <bits/stdc++.h>
using namespace std;

const int maxx = 100100;
long long sum[maxx], ans = -(1 << 62);

int main()
{
  //freopen("happy20.in","r",stdin);
  //freopen("happy20.ans","w",stdout);
  int n,p,q;
  cin>>n>>p>>q;
  for(int i = 1; i <= n; i++)
    scanf( "%lld", &sum[i] ), sum[i] += sum[i - 1];
  int que[maxx], h = 0, t = 0;
  que[++t] = 0;
  for(int i = 1; i <= n; i++)
  {
    for(; h < t && i - que[h + 1] > q; h++);
    ans = max(ans, sum[i] - sum[que[h + 1]]);
    for(; h < t && i >= p + 1 && sum[i - p + 1] <= sum[que[t]]; t--);
    if(i >= p + 1) que[++t] = i - p + 1;
  }
  cout<<ans<<endl;
}

