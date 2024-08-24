#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("HappySort10.in","w",stdout);
  srand(time(0));
  int n=100000;
  cout<<n<<endl;
  for(int i=1; i<=n; i++)
    cout<<rand()%100000<<" ";
  return 0;
}

