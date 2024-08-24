//K个最大连续子序列和
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int f[11][1001];                            //注意此处的行列定义是相反的

int main()
{
  //freopen("ksum.in","r",stdin);
  //freopen("ksum.out","w",stdout);
  int k,n;
  cin>>n>>k;
  for(int i=1; i<=n; ++i)
    cin>>a[i];
  for(int i=1; i<=k; ++i)
    for(int j=1; j<=n; ++j)
    {
      f[i][j]=f[i][j-1]+a[j];               //接在j-1后面
      for(int m=i-1; m<=j-1; ++m)           //另起一段
        f[i][j]=max(f[i-1][m]+a[j],f[i][j]);
    }
  int Max=f[k][k];
  for(int j=k; j<=n; ++j)                   //找出最大值
    Max=max(Max,f[k][j]);
  cout<<Max<<endl;
  return 0;
}
