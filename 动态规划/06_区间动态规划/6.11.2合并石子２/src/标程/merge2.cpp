//合并魔法石2
#include <bits/stdc++.h>
using namespace std;

int f1[101][101],f2[101][101];
int v[201], s[201];

inline int d(int i,int j)                 //内联函数加速
{
  return s[j]-s[i-1];
}

int main()
{
  //freopen("merge2.in","r",stdin);
  //freopen("merge2.out","w",stdout);
  int n;
  scanf("%d",&n);
  for (int i=1; i<=n; i++)
  {
    scanf("%d",&v[i]);
    v[n+i]=v[i];			                // 把环扩展成链
  }
  for(int i=1; i<=n+n; i++)
    s[i]=s[i-1]+v[i];		                // 前序和
  for (int p=1; p<n; p++)
    for (int i=1,j=i+p; (i<n+n) && j<=(n+n); i++,j=i+p)
    {
      f1[i][j]=0;
      f2[i][j]=1<<30;
      for (int k=i; k<j; k++)
      {
        f1[i][j]=max(f1[i][j],f1[i][k]+f1[k+1][j]+d(i,j));
        f2[i][j]=min(f2[i][j],f2[i][k]+f2[k+1][j]+d(i,j));
      }
    }
  int r1=-(1<<30), r2=1<<30;
  for(int i=1; i<=n; i++)
  {
    r1=max(f1[i][i+n-1],r1);
    r2=min(f2[i][i+n-1],r2);
  }
  printf("%d %d\n",r1,r2);
  return 0;
}

