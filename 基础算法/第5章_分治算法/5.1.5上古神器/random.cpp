#include <bits/stdc++.h>
using namespace std;
int a[100010];

int main()
{
  //freopen("danger10.in","w",stdout);
  set <int> s;

  srand(unsigned(time(0)));
  int n=100000;
  int p=rand()%n+1;
  while(s.size()<n)
  {
    int t=rand()*rand()%1000000000;
    s.insert(t);
  }
  cout<<n<<" "<<p<<endl;
  set<int>::iterator ii;
  int i=0;
  for(ii=s.begin(); ii!=s.end(); ii++)
    a[i++]=*ii;
  for(int i=0; i<n; i++)
  {
    int x=rand()%n;
    int y=rand()%n;
    swap(a[x],a[y]);
  }
  for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
  return 0;
}

