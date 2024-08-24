//加分二叉树
#include <bits/stdc++.h>
using namespace std;

int n,dp[35][35],root[35][35];

void Out(int x,int y)         //递归输出
{
  if(x<=y)
  {
    printf("%d ",root[x][y]);
    Out(x,root[x][y]-1);
    Out(root[x][y]+1,y);
  }
}

int Search(int l,int r)       //寻找区间(l,r)之间的最大值
{
  if(dp[l][r]>0 || l==r)
    return dp[l][r];
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

int main()
{
  //freopen("tree.in","r",stdin);
  //freopen("tree.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&dp[i][i]),root[i][i]=i;
  printf("%d\n",Search(1,n));
  Out(1,n);
  return 0;
}
