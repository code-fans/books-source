#include <bits/stdc++.h>
using namespace std;
int f[10]= {1,2,3,4,5,6,7,8,9,0};
int main()
{
  //freopen("sub.in","w",stdout);
  srand(time(0));
  int n;
  cin>>n;
  cout<<n<<endl;
  for(int i=0; i<n; i++)
  {
    int x=f[rand()%9];
    cout<<x;
    x=rand()%99+1;
    for(int i=0; i<x; i++)
      cout<<f[rand()%10];
    cout<<endl;
  }
  return 0;
}

