//加分二叉树
#include <bits/stdc++.h>
using namespace std;

long long f[35][35];
int root[35][35];                            //root[x][y]保存x,y区间的父结点

void Out(int x,int y)                        //递归输出
{
  if(x<=y)
  {
    printf("%d ",root[x][y]);
    Out(x,root[x][y]-1);
    Out(root[x][y]+1,y);
  }
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
      f[i][j]=1,root[i][i]=i;
  for(int i=1; i<=n; i++)
    scanf("%d",&f[i][i]);
  for(int i=n; i>=1; i--)                          //i递减以控制区间范围递增
    for(int j=i+1; j<=n; j++)
      for(int k=i; k<=j; k++)
        if(f[i][j]<(f[i][k-1]*f[k+1][j]+f[k][k]))//如果有更优解
        {
          f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
          root[i][j]=k;                          //标记更优解的根
        }
  printf("%lld\n",f[1][n]);
  Out(1,n);
  return 0;
}
