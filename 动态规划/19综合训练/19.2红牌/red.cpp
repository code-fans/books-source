//类似于数字三角形
#include <bits/stdc++.h>
using namespace std;
const int inf =0x7fffffff;

int f[2005][2005],n,m,ans=inf;

int main()
{
  cin>>n>>m;
  for(int i=1; i<=m; i++)//注意读取顺序 
    for(int j=1; j<=n; j++)
      cin>>f[i][j];
  for(int i=2; i<=n; i++)//i为步骤 
    for(int j=1; j<=m; j++)//j为组 
    {
      if(j==1)
        f[j][i]+=min(f[1][i-1],f[m][i-1]);
      else
        f[j][i]+=min(f[j][i-1],f[j-1][i-1]); 
    }
  for(int i=1; i<=m; i++)
    ans=min(ans,f[i][n]);//取所有组的最小值
  cout<<ans<<endl;
  return 0;
}

