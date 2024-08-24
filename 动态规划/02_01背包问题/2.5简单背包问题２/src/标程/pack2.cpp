#include<bits/stdc++.h>
using namespace std;

int v,n,f[20005];
int main()
{
  //freopen("pack2.in","r",stdin);
  //freopen("pack2.out","w",stdout);
  int j,w;
  cin>>v>>n;
  for(int i=1; i<=n; ++i)
    for(cin>>w,j=v; j>=w; --j)
      if(f[j]<f[j-w]+w)
        f[j]=f[j-w]+w;
  cout<<v-f[v]<<'\n';
  return 0;
}
