//理想收入问题 - 优化算法1
#include <bits/stdc++.h>
using namespace std;

double q[100010],v[100010];

int main()
{
  freopen("stock.in","r",stdin);
  freopen("stock.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>v[i];
  q[1]=1;
  for(int i=1; i<=n; i++)
    for(int j=1; j<i; j++)
      q[i]=max(q[i-1],q[j]/v[j]*v[i]);
  cout<<setprecision(4)<<fixed<<q[n]<<'\n';
  return 0;
}

