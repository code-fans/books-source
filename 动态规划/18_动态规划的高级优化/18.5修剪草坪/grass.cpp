#include <bits/stdc++.h>
using namespace std;
const int N=100005;

deque<int>q;
long long f[N];

int main()
{
  //freopen("grass.in","r",stdin);
  //freopen("grass.out","w",stdout);
  int n,k;
  long long sum=0,Min=1e+18;
  scanf("%d%d",&n,&k);
  q.push_back(0);
  for(int i=1; i<=n; ++i)
  {
    scanf("%d",&f[i]);
    sum+=f[i];                            //前缀和 
    while(!q.empty() && i-q.front()>k+1)  //维护队列长 
      q.pop_front();
    if(!q.empty())
      f[i]=f[q.front()]+f[i];
    while(!q.empty() && f[i]<=f[q.back()])//维护单调性 
      q.pop_back();
    q.push_back(i);
  }
  for(int i=n-k; i<n; ++i)
    Min=min(Min,f[i]);
  printf("%lld\n",sum-Min);
  return 0;
}

