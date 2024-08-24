//电视节目安排
#include <bits/stdc++.h>
using namespace std;

int main()
{
// freopen("tv.in","r",stdin);
  freopen("tv.in","w",stdout);
  srand(time(0));
  int n,T;
  cin>>T>>n;
  for(int j=1; j<=T; j++)
  {
    cout<<n<<endl;
    for(int i=1; i<=n; i++)
    {
      int x=rand()%1000+1;
      int y=x+rand()%1000;
      cout<<x<<" "<<y<<endl;
    }
  }
  cout<<0<<endl;
  return 0;
}

