#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  //freopen("Assemble6.in","w",stdout);
  int t=99;
  cout<<t<<endl;
  for(int ij=1; ij<=t; ij++)
  {
    int n=100;
    set <string> type;
    type.clear();
    set <string> name;
    name.clear();
    string st;

    while(type.size()<n)
    {
      st="";
      for(int i=0; i<=10; i++)
        st+=(char)(rand()%(26)+1+96);
      type.insert(st);
    }
    string t[100];
    int i=0;
    set <string>::iterator ii;
    for(ii=type.begin(); ii!=type.end(); ii++)
      t[i++]=*ii;

    while(name.size()<n*10)
    {
      st="";
      for(int i=0; i<=5; i++)
        st+=(char)(rand()%(26)+1+96);
      name.insert(st);
    }
    string nn[1000];
    i=0;
    for(ii=name.begin(); ii!=name.end(); ii++)
      nn[i++]=*ii;
    cout<<n*10<<" "<<rand()*1000<<endl;
    for(int i=0; i<n*10; i++)
    {
      int xy=rand()%n;
      cout<<t[xy]<<" "<<nn[i]<<" "<<rand()<<" "<<rand()<<endl;
    }
  }
  return 0;
}

