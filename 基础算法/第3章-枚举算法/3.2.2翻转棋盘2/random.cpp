#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  freopen("flip.in","r",stdin);
  freopen("flip.in","w",stdout);
  int n=rand()%11+6;
  cout<<n<<endl;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      cout<<(rand()%2?'b':'w');
    cout<<endl;
  }
}
