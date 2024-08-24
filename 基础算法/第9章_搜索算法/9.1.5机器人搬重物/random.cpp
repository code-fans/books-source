#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("a.in","r",stdin);
  //freopen("robot10.in","w",stdout);

  int m,n;
  srand(time(0));
  m=50,n=50;
  cout<<m<<' '<<n<<endl;
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++)
    {
      int k=rand()%5;
      if(k==0)
        cout<<1<<' ';
      else
        cout<<0<<' ';
    }
    cout<<endl;
  }

  return 0;
}
