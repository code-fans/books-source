#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("ghost10.in","w",stdout);
  set <int> s;
  srand(time(0));
  int n=5000;
  int l=9900;
  while(s.size()<n)
  {
    int k=rand()%5000+1;
    s.insert(k);
  }
  int a[n];
  set <int>::iterator it;
  int i=0;
  for(it=s.begin(); it!=s.end(); it++)
  {
    a[i++]=*it;
  }
  for(int i=0; i<n; i++)
  {
    int x=rand()%n;
    int y=rand()%n;
    swap(a[x],a[y]);
  }
  cout<<n<<endl<<l<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<a[i]<<" ";
  }
}
