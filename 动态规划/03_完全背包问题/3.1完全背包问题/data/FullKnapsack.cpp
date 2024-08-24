//完全背包问题
#include<bits/stdc++.h>
using namespace std;
int f[10001];
int main()
{
  //freopen("FullKnapsack5.in","r",stdin);
  //freopen("FullKnapsack5.ans","w",stdout);
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
