//理想收入问题 - 优化算法2
#include <bits/stdc++.h>
using namespace std;

double v[100010],p[100010];

int main()
{
  freopen("stock.in","r",stdin);
  freopen("stock.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>v[i];
  p[1]=1.0/v[1];
  for(int i=1; i<=n; i++)
    for(int j=1; j<i; j++)
      p[i]=max(p[i-1],p[j]*v[j]/v[i]);
  cout<<setprecision(4)<<fixed<<p[n]*v[n]<<'\n';
  return 0;
}

