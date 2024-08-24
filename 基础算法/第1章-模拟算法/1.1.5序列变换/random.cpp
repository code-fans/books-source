//–Ú¡–±‰ªª
#include <bits/stdc++.h>
using namespace std;

int main()
{
// freopen("change.in","r",stdin);
  freopen("change.in","w",stdout);
  srand(time(0));
  int n,m;
  cin>>n>>m;
  n=n%1000000;
  m=m%100000;
  cout<<n<<" "<<m<<endl;
  for(int i=0; i<n; i++)
    cout<<int(pow(-1,rand()%2)*rand()*rand())%1000000<<" ";
  cout<<endl;
  int count=0;
  for(int i=0; i<m; i++)
  {
    int k=rand()%2+1;
    if(k==2)
      count++;
    if(count>10000)
      k=1;
    if(k==1)
      cout<<1<<" "<<rand()%(n/10)+1<<" "<<1+int(pow(-1,rand()%2)*rand()*rand())%100000<<endl;
    else
      cout<<2<<" "<<rand()%(n-1)+1<<endl;
  }
  return 0;
}
