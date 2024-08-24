#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long sum[MAXN+10], f[MAXN+10];
typedef pair<int, long long> pii;
deque<pii> que;

int main()
{
  freopen("grass.in","r",stdin);
  freopen("grass.out","w",stdout);
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++)
  {
    scanf("%I64d", &sum[i]);
    sum[i] += sum[i-1];
  }
  que.push_back(make_pair(0, -sum[1]));
  for(int i=1; i<=k; i++)
  {
    f[i] = sum[i];
    long long v = f[i] - sum[i+1];
    while(!que.empty() && que.back().second <= v) que.pop_back();
    que.push_back(make_pair(i, v));
  }
  for(int i=k+1; i<=n; i++)
  {
    while(!que.empty() && que.front().first < i-k-1) que.pop_front();
    f[i] = sum[i] + que.front().second;
    long long v = f[i] - sum[i+1];
    while(!que.empty() && que.back().second <= v) que.pop_back();
    que.push_back(make_pair(i, v));
  }
  printf("%I64d\n", f[n]);

  return 0;
}

