//完全背包问题　—优化算法
#include<bits/stdc++.h>
using namespace std;
int f[10001];
int main()
{
  freopen("FullKnapsack.in","r",stdin);
  freopen("FullKnapsack.out","w",stdout);
  int m,n;
  cin>>m>>n;
  for(int i=1,w,c; i<=n; i++)
  {
    cin>>w>>c;
    for(int j=w; j<=m; ++j)
      f[j]=max(f[j-w]+c,f[j]);
  }
  cout<<f[m]<<endl;
  return 0;
}
