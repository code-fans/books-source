//最朴素的求X的N次方
#include <bits/stdc++.h>
using namespace std;

unsigned long long Power(unsigned long long n,unsigned long long p)
{
  if(p==0)
    return 1;
  unsigned long long result=1;
  for(int i=0; i<p; i++)
    result*=n;
  return result;
}

int main()
{
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  int n,p;
  cin>>n>>p;
  cout<<Power(n,p)<<endl;
  return 0;
}
