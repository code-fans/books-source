#include <bits/stdc++.h>
using namespace std;
int prime[]= {3,7,11,13,17,19,23,29,31,37,41,43,47};

int main()
{
  //freopen("emm7.in","r",stdin);
  //freopen("emm7.in","w",stdout);
  srand(time(0));
  int n=5;
  while(n--)
  {
    cout<<65<<endl;
    for(int i=1; i<=65; i++)
    {
      cout<<prime[rand()%13]<<" ";
    }
    cout<<endl;
  }
  cout<<0<<endl;
}

