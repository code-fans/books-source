//ÄæĞòÊı×é
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  int n,a[1002];
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i];
  for(int i=0; i<n/2; i++)
    swap(a[i],a[n-1-i]);
  for(int i=0; i<n-1; i++)
    cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;
  return 0;
}

