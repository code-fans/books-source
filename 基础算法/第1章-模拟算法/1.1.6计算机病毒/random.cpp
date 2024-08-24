//计算机病毒
//模拟即可
#include <bits/stdc++.h>
using namespace std;

int a[101][101];
char b[101][101];

int main()
{
  //freopen("virus10.in","w",stdout);
  srand(time(0));
  int n=100;
  cout<<n<<endl;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      int k=rand()%20;
      if(k==0)
        cout<<'@';
      else if(k==1)
        cout<<'#';
      else
        cout<<'*';
    }
    cout<<endl;
  }
  cout<<34<<endl;
  return 0;
}

