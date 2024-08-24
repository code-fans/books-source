#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  freopen("FlipGame.in","r",stdin);
  freopen("FlipGame.in","w",stdout);
  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
      cout<<(rand()%2?'b':'w');
    cout<<endl;
  }
}
