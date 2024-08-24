//ÐÐ±à¼­Æ÷
#include<bits/stdc++.h>
using namespace std;

string s;
char a[5005];
int p;

int main()
{
  freopen("LineEditor.in","r",stdin);
  freopen("LineEditor.out","w",stdout);
  getline(cin,s);
  int Len=s.size();
  for(int i=0; i<Len; ++i)
  {
    if(s[i]=='@')
      p=0;
    else if(s[i]=='#' && p>0)
      --p;
    else if(s[i]!='#')
      a[++p]=s[i];
  }
  for(int i=1; i<=p; ++i)
    cout<<a[i];
  cout<<'\n';
  return 0;
}

