//朴素对拍程序
#include <bits/stdc++.h>
#define LL long long
#define MAXN 100010
using namespace std;
LL n, num[MAXN], a[MAXN], b[MAXN], sum[MAXN];

int main()
{
  //freopen("feel.in","r",stdin);
  //freopen("feel.out","w",stdout);
  cin>>n;
  sum[0] = 0;
  for (int i = 1; i <= n; ++i)//求前序列和
  {
    cin>>num[i];
    sum[i] = sum[i - 1] + num[i];
  }
  num[0] = num[n + 1] = -INT_MAX;//序列两端均初始化
  a[0] = -1;
  for (int i = 1; i <= n; ++i)//初始化，各点左端均初始为自身
    a[i] = i;
  for (int i = 1; i <= n; ++i)//求a[i]的值
    while (num[a[i] - 1] >= num[i])
      a[i] = a[a[i] - 1];
  b[n + 1] = -1;
  for (int i = 1; i <= n; ++i)//初始化，各点右端均初始为自身
    b[i] = i;
  for (int i = n; i >= 1; --i)//求b[i]的值
    while (num[b[i] + 1] >= num[i])
      b[i] = b[b[i] + 1];
  LL max_res = 0;
  for (int i = 1; i <= n; ++i)
    max_res = max(max_res, (sum[b[i]] - sum[a[i] - 1]) * num[i]);
  cout<<max_res<<endl;
  for (int i = 1; i <= n; ++i)
    if ((sum[b[i]] - sum[a[i] - 1]) * num[i] == max_res)
    {
      cout<<a[i]<<" "<<b[i]<<endl;
      break;
    }
  return 0;
}

