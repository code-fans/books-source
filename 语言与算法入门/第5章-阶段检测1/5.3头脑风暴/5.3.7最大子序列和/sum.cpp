//求最大子序列和 方法5
#include <bits/stdc++.h>
using namespace std;
int a[35000];

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  int i,n,sum=-2147483647,b=0;
  cin>>n;
  for(i=1; i<=n; ++i)
    cin>>a[i];
  for(i=n; i>=1; --i)
  {
    b+=a[i];
    if(b>sum)
      sum=b;
    if(b<0)
      b=0;
  }
  cout<<sum<<endl;
  return 0;
}
