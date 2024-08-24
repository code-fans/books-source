#include <bits/stdc++.h>
using namespace std;

int main()
{
  double a,k=1,count=0;
  cin>>a;
  while(count<a-1)
  {
    ++count;
    cout<<((k*k/2)+(k/2))*k<<" ";
    k++;
  }
  cout<<((a*a/2)+(a/2))*k<<endl;
  return 0;
}
