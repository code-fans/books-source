//最大连续子序列积
#include <bits/stdc++.h>
using namespace std;

long long maxx=-9223372036854775800LL,minn=9223372036854775800ll;
long long a[1001],g[1001],f[1001];

int main()
{
  freopen("Cproduct.in","r",stdin);
  freopen("Cproduct.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    f[i]=g[i]=a[i];
    f[i]=max(f[i],f[i-1]*a[i]);
    f[i]=max(f[i],g[i-1]*a[i]);
    g[i]=min(g[i],f[i-1]*a[i]);
    g[i]=min(g[i],g[i-1]*a[i]);
    maxx=max(maxx,f[i]);
    minn=min(minn,g[i]);
  }
  cout<<maxx<<endl<<minn<<endl;
  return 0;
}

