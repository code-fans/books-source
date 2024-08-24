#include <bits/stdc++.h>
using namespace std;
string ss[100000];
int main()
{
  freopen("dictionary10.in", "w", stdout);
  srand(unsigned(time(0)));
  set <string> s;
  int n=100000;
  while(s.size()<n)
  {
    string str;
    for(int j=0; j<10; j++)
    {
      str+=(char)(rand()%26+1+96);
    }
    s.insert(str);
  }
  set <string>::iterator ii;
  int u=0;
  for(ii=s.begin(); ii!=s.end(); ii++)
  {
    string s1=*ii;
    cout<<s1<<' ';
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;
    ss[u++]=s1;
  }
  cout<<endl;
  for(int i=1; i<=n; i++)
  {
    int t=rand()%2;
    if(t)
    {
      int k=rand()%(n-1);
      cout<<ss[k]<<endl;
    }
    else
    {
      string str;
      for(int j=0; j<10; j++)
      {
        str+=(char)(rand()%26+1+96);
      }
      cout<<str<<endl;
    }
  }
  return 0;
}

