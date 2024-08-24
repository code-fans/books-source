//NOI
#include <bits/stdc++.h>
using namespace std;

long long len,N,NO,NOI;

int main()
{
  //freopen("NOI.in","r",stdin);
  //freopen("NOI.out","w",stdout);
  cin>>len;
  getchar();                   //消去回车符
  string st;
  getline(cin,st);
  for(int i=0; i<len; i++)
  {
    if(st[i]=='N')
      N++;
    if(st[i]=='O')
      NO+=N;
    if(st[i]=='I')
      NOI+=NO;
  }
  cout<<NOI<<endl;
  return 0;
}

