//求中间数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("mid.in","r",stdin);
  freopen("mid.out","w",stdout);
  int a,b,c;
  cin>>a>>b>>c;
  if(a>b && b>c)
    cout<<b<<endl;
  else if(c>b && b>a)
    cout<<b<<endl;
  else if(b>a && a>c)
    cout<<a<<endl;
  else if(c>a && a>b)
    cout<<a<<endl;
  else if(a>c && c>b)
    cout<<c<<endl;
  else if(b>c && c>a)
    cout<<c<<endl;
  return 0;
}

