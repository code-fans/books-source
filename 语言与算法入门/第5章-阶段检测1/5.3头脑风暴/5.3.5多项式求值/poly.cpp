//多项式求值
#include <bits/stdc++.h>
using namespace std;
int a[20];

int main()
{
  //freopen("poly.in","r",stdin);
  //freopen("poly.out","w",stdout);
  int n,x;
  cin>>n>>x;
  for(int i=0; i<=n; i++)
    cin>>a[i];
  int ans=a[n];
  for(int i=n-1; i>=0; i--)
    ans=ans*x+a[i];
  cout<<ans<<endl;
  return 0;
}

