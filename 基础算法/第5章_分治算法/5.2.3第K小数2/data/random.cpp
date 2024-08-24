#include <bits/stdc++.h>
using namespace std;
#define n 100000

int main()
{
  //freopen("k210.in","w",stdout);
  srand(time(0));
  int a[n],b[n];
  set <int> s1,s2;
  while(s1.size()<n)
  {
    int t=rand()*rand();
    s1.insert(t);
  }
  while(s2.size()<n)
  {
    int t=rand()*rand();
    s2.insert(t);
  }
  int k=170009;
  cout<<s1.size()<<" "<<s2.size()<<" "<<k<<endl;
  set <int>::iterator ii;
  for(ii=s1.begin(); ii!=s1.end(); ii++)
    cout<<*ii<<" ";
  cout<<endl;
  for(ii=s2.begin(); ii!=s2.end(); ii++)
    cout<<*ii<<" ";
  return 0;
}

