//子矩阵变形问题－搜索
#include <bits/stdc++.h>
using namespace std;

int m,n,w,h;

int a[5001][5001];

int main()
{
  freopen("bombing.in","r",stdin);
  freopen("bombing.out","w",stdout);
  int Max=-INT_MAX,sum;
  cin>>m>>n>>w>>h;
  for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j)
      cin>>a[i][j];
  for(int i=1; i<=m-w+1; ++i)
    for(int j=1; j<=n-h+1; ++j)
    {
      sum=0;
      for(int k=i; k<=i+w-1; ++k)
        for(int l=j; l<=j+h-1; ++l)
          sum+=a[k][l];
      Max=max(Max,sum);
    }
  cout<<Max<<endl;
  return 0;
}
