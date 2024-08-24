//求子集-位运算
#include<bits/stdc++.h>
using namespace std;

int N;
set <string> s;

void Subset(int n)
{
  string str="(";
  for(int i=0; i<N; i++)
    if((1<<i)&n)
      str+=char(i+'a');
  str+=")";
  s.insert(str);
}

int main()
{
  freopen("Subset.in","r",stdin);
  freopen("Subset.out","w",stdout);
  cin>>N;
  for(int i=0; i<(1<<N); i++) //循环2^N次
    Subset(i);
  for(auto ii=s.begin(); ii!=s.end(); ii++)
    cout<<*ii<<endl;
  return 0;
}
