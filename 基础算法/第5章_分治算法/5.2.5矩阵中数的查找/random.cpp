#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("matrix1.in","w",stdout);
  srand(time(0));
  int n=50;
  cout<<n<<endl;
  for(int i=1; i<=n; i++)
  {
    int x=rand()%5000;
    cout<<x<<" "<<rand()%(x*x-1)<<endl;
  }
  return 0;
}

