//ур╧Фби3
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a=1,b=1,j=2,n;
  cin>>n;
  while(a<=n)
  {
    cout<<a*b<<(a==n?'\n':' ');
    a++;
    b+=j;
    j++;
  }
  return 0;
}
