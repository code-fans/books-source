//¼Ó·Ö¶þ²æÊ÷
#include <bits/stdc++.h>
using namespace std;

int n,dp[35][35],root[35][35];

int Search(int l,int r)
{
  if(dp[l][r]>0)
    return dp[l][r];
  if(l==r)
    return dp[l][l];
  if(r<l)
    return 1;
  for(int i=l; i<=r; i++)
  {
    int p=Search(l,i-1)*Search(i+1,r)+dp[i][i];
    if(p>dp[l][r])
    {
      dp[l][r]=p;
      root[l][r]=i;
    }
  }
  return dp[l][r];
}

void Dfs(int l,int r)
{
  if(r<l)return;
  if(l==r)
  {
    printf("%d ",l);
    return;
  }
  printf("%d ",root[l][r]);
  Dfs(l,root[l][r]-1);
  Dfs(root[l][r]+1,r);
}

int main()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&dp[i][i]);
  printf("%d\n",Search(1,n));
  Dfs(1,n);
  return 0;
}
