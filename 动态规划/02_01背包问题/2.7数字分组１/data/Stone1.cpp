//Êý×Ö·Ö×é1 - DFS
#include <bits/stdc++.h>
using namespace std;
#define INF 20000007

int n,sum,ans=INF,w[27];

void DFS(int dep,int now)
{
  if(dep>n)
  {
    if(ans>abs(now-(sum-now)))
      ans=abs(now-(sum-now));
    return;
  }
  DFS(dep+1,now);
  DFS(dep+1,now+w[dep]);
}

int main()
{
  freopen("Stone1.in","r",stdin);
  freopen("Stone1.out","w",stdout);
  scanf("%d",&n);
  for(long i=1; i<=n; i++)
  {
    scanf("%d",&w[i]);
    sum+=w[i];
  }
  DFS(1,0);
  printf("%d\n",ans);
  return 0;
}

