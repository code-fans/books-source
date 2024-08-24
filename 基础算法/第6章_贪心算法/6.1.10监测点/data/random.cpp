//¼à²âµã
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("ChoicePoint.in","r",stdin);
  freopen("ChoicePoint.in","w",stdout);
  int x,n;
  cin>>x>>n;
  cout<<x<<endl;
  srand(time(0));
  for(int i=1; i<=x; i++)
  {
    cout<<n<<endl;
    for(int j=1,a,b; j<=n; j++)
    {
      do
      {
        a=rand()%100+1;
        b=rand()%100+1;
      }
      while(a==b);
      if(a>b)
        swap(a,b);
      cout<<a<<" "<<b<<endl;
    }

  }

  return 0;
}

