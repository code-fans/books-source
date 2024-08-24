//包含49 - DFS
#include <bits/stdc++.h>
using namespace std;
# define ll long long

ll dp[50][10];
int a[50];

ll DFS(int pos,int pre,bool limit)
{
  if(pos == -1)
    return 1;
  if(!limit && dp[pos][pre] != -1)               //直接取值
    return dp[pos][pre];

  int up = limit?a[pos]:9;
  ll ans = 0;
  for(int i = 0; i <= up; i++)
    if(pre == 4 && i == 9)
      continue;
    else
      ans += DFS(pos-1,i,limit && i == a[pos]);
  if(!limit)
    dp[pos][pre] = ans;                          //保存算好的值
  return ans;
}

ll Work(ll x)
{
  int len = 0;
  while(x)
  {
    a[len++] = x % 10;
    x /= 10;
  }
  return DFS(len-1,0,1);
}

int main()
{
  freopen("statistics5.in","r",stdin);
  freopen("statistics5.ans","w",stdout);
  int T;
  scanf("%d",&T);
  memset(dp,-1,sizeof(dp));
  ll N;
  while(T--)
  {
    scanf("%lld",&N);
    printf("%lld\n",N-Work(N)+1);      //+1是因为程序是从0开始的，但题目是从1开始
  }
  return 0;
}

