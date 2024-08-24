//最长公共上升子序列 - 朴素算法
#include <bits/stdc++.h>
using namespace std;
#define MAX 555

int n,m,a[MAX],b[MAX],f[MAX][MAX],from[MAX];

void Out(int u)                                         //递归输出子序列
{
  if(from[u])
    Out(from[u]);
  if(u!=n+1)
    cout<<a[u]<<" ";
}

int main()
{
  freopen("LCIS.in","r",stdin);
  freopen("LCIS.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  a[n+1]=1<<30;
  cin>>m;
  for(int j=1; j<=m; j++)
    cin>>b[j];
  b[m+1]=1<<30;
  for(int i=1; i<=n+1; i++)
    for(int j=1; j<=m+1; j++)
      for(int k=0; k<i; k++)
        for(int h=0; h<j; h++)
          if(a[i]==b[j] && a[k]==b[h] && a[i]>a[k] && f[k][h]+1>f[i][j])
            f[i][j]=f[k][h]+1,from[i]=k;
  cout<<f[n+1][m+1]-1<<endl;
  Out(n+1);
  return 0;
}

