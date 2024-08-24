#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("k19.in","w",stdout);
  int n=100000-1;
  set <int> s;
  srand(time(0));
  while(s.size()<n)
  {
    int x=rand()%2;
    int u=rand()*rand();
    if(x==1)
      u=-1;
    s.insert(u);
  }
  int k=0,a[n];
  set <int>::iterator ii;
  for(ii=s.begin(); ii!=s.end(); ii++)
  {
    a[k++]=*ii;
  }
  for(int i=0; i<=99999; i++)
  {
    int x=rand()%n;
    int y=rand()%n;
    swap(a[x],a[y]);
  }
  cout<<n<<endl;
  for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
}
