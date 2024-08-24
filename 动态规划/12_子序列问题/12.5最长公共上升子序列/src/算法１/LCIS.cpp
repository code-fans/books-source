//最长公共上升子序列 - 朴素算法
#include <bits/stdc++.h>
using namespace std;
#define MAX 555

int n,m,i,j,k,h,a[MAX],b[MAX],f[MAX][MAX],from[MAX];

void Dfs(int u)                                         //递归输出子序列
{
  if(from[u])
  {
    Dfs(from[u]);
    cout<<' ';
  }
  if(u!=n+1)
    cout<<a[u];
}

int main()
{
  //freopen("LCIS.in","r",stdin);
  //freopen("LCIS.out","w",stdout);
  for(cin>>n,i=1; i<=n; i++)
    cin>>a[i];
  a[n+1]=MAX;
  for(cin>>m,j=1; j<=m; j++)
    cin>>b[j];
  b[m+1]=MAX;

  for(i=1; i<=n+1; i++)
    for(j=1; j<=m+1; j++)
      for(k=0; k<i; k++)
        for(h=0; h<j; h++)
          if(a[i]==b[j] && a[k]==b[h] && a[i]>a[k] && f[k][h]+1>f[i][j])
            f[i][j]=f[k][h]+1,from[i]=k;
  cout<<f[n+1][m+1]-1<<endl;
  Dfs(n+1);
  return 0;
}

