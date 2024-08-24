#include <bits/stdc++.h>
using namespace std;
int a[26];

int main()
{
  freopen("book10.in","r",stdin);
  freopen("check.txt","w",stdout);
  int n,m;
  cin>>n>>m;
  string str;
  cin>>str;
  for(int i=0; i<str.size(); i++)
    a[str[i]-'a']=1;
  int sum=0;
  for(int i=0; i<26; i++)
    sum+=a[i];
  cout<<sum<<endl;
  return 0;
}

