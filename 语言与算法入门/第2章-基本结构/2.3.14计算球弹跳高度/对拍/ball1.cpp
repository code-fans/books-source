//ÇòµÄµ¯Ìø¸ß¶È
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("ball.in","r",stdin);
  //freopen("ball2.out","w",stdout);
  double h;
  cin>>h;
  double dist=h;
  int i=1;
  while(i<10)
  {
    i++;
    dist+=h;
    h/=2;
  }
  cout<<setprecision(3)<<fixed<<dist<<endl;
  cout<<h/2<<endl;
  return 0;
}

