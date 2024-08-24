//ур╧Фби3
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i=1;
  cin>>n;
  while(i<=n)
    cout<<(i*i*(i+1)/2+(++i)-i)<<(i!=n?" ":"\n");
  return 0;
}
