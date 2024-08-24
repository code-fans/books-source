//program1.cpp，普通写法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("in.txt","r",stdin); //从in.txt中读取数据
  freopen("out1.txt","w",stdout);//注意此处为out1.txt
  long long a,b,c;
  cin>>a>>b>>c;
  cout<<a*b%c<<endl;
  return 0;
}

