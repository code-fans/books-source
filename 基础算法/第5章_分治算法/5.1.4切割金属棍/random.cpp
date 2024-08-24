#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("cut10.in","w",stdout);
  srand(unsigned(time));
  int n=300;
  int k=10000;
  cout<<n<<" "<<k<<endl;
  for(int i=1; i<=n; i++)
    cout<<rand()*rand()%1000+1<<"."<<rand()%100<<" ";
  return 0;
}

