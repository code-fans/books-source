#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  freopen("sort.in","w",stdout);
  int n,r;
  cin>>n>>r;
  cout<<n<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<rand()%r+1<<' '<<rand()%r+1<<endl;
  }
  return 0;
}

