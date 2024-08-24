//任务
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;

int N;
int first[MAXN],Next[MAXN*100],ver[MAXN*100],idx;//注意Next要大写
int t[MAXN];
int dp[MAXN];
queue<int> Q;

void AddEdge(int u,int v)
{
  Next[++idx] = first[u];
  ver[idx] = v;
  first[u] = idx;
}

int Solve(int p)
{
  if(dp[p])
    return dp[p];
  int res = 0;
  for(int i = first[p]; i != -1; i = Next[i])
  {
    int v = ver[i];
    res = max(res,Solve(v));
  }
  return dp[p] = res + t[p];
}

int main()
{
  freopen("chore.in","r",stdin);
  freopen("chore.out","w",stdout);
  scanf("%d",&N);
  memset(first,-1,sizeof(first));
  idx = 0;
  memset(dp,0,sizeof(dp));
  int num,pre;
  for(int i = 1; i <= N; ++i)
  {
    scanf("%d%d",&t[i],&num);
    if(num == 0)
      Q.push(i);
    for(int j = 1; j <= num; ++j)
    {
      scanf("%d",&pre);
      AddEdge(pre,i);
    }
  }
  int ans = 0;
  while(!Q.empty())
  {
    int x = Q.front();
    Q.pop();
    ans = max(ans,Solve(x));
  }
  printf("%d\n",ans);
  return 0;
}
