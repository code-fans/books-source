//最小交通费用问题--Floyd算法
#include <bits/stdc++.h>
using namespace std;
const int MAXN=101;

int n;
int a[MAXN][MAXN];

void Floyd()
{
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        if(a[i][k]+a[k][j]<a[i][j])
          a[i][j]=a[i][k]+a[k][j];
}

int main()
{
  freopen("cost.in","r",stdin);
  freopen("cost.out","w",stdout);
  memset(a,60,sizeof(a));              //赋值为1010580540
  int m,u,v,s,t;
  cin>>n>>m;
  for(int i=1; i<=m; i++)
  {
    cin>>u>>v;
    cin>>a[u][v];
  }
  cin>>s>>t;
  Floyd();
  cout<<a[s][t]+a[t][s]<<endl;
  return 0;
}

