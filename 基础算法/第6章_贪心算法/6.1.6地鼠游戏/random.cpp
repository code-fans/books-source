#include<algorithm>
#define T 1000000/*保证T*N不超过一秒的理论最大值*/
#include<iostream>
using namespace std;
#include<cstdio>

int main()
{
  freopen("mouse.in","w",stdout);
  long long n;
  cin>>n;
  cout<<n<<endl;
  for(int i=0; i<n; i++)
    cout<<rand()*rand()%(10+1)<<" ";
  cout<<endl;
  for(int i=0; i<n; i++)
    cout<<rand()*rand()%(10+1)<<" ";
  return 0;
}
