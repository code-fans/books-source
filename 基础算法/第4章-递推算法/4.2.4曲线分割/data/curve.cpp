//ÇúÏß·Ö¸î
#include <bits/stdc++.h>
using namespace std;

int F(int n)
{
  return (n==1?2:F(n-1)+2*(n-1));
}

int main()
{
  freopen("curve.in","r",stdin);
  freopen("curve.out","w",stdout);
  int n;
  cin>>n;
  cout<<F(n)<<endl;
  return 0;
}
