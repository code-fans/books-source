//¶ş²æÊ÷ÎÊÌâ
#include <bits/stdc++.h>
using namespace std;

long long a[30]= {1,1};

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  for(int i=2; i<=29; i++)
    for(int j=0; j<=i-1; j++)
      a[i]+=a[j]*a[i-1-j];
  int n;
  while(cin>>n)
    cout<<a[n]<<endl;
  return 0;
}

