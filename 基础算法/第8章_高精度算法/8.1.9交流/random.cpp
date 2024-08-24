//random
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("chat.in","r",stdin);
  freopen("chat.in","w",stdout);
  srand(time(0));
  int n=rand()%998+3;
  cout<<n<<endl;
  for(int i=0; i<n; i++)
  {
    int k=rand()%1000+1;
    cout<<rand()%9+1;
    for(int j=0; j<k-1; j++)
      cout<<rand()%10;
    cout<<endl;
  }
  return 0;
}
