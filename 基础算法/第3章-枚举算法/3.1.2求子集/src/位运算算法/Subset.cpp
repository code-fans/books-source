//求子集 - 位运算
#include <bits/stdc++.h>
using namespace std;

int N;
set <string> s;

void Subset(int n)
{
  string str="(";
  for(int i=0; i<N; i++)
    if((1<<i) & n)                  //如果当前位是1
      str+=char(i+'a');
  s.insert(str+")");                //产生的子集插入set容器,set会自动排序
}

int main()
{
  freopen("Subset.in","r",stdin);
  freopen("Subset.out","w",stdout);
  cin>>N;
  for(int i=0; i<(1<<N); i++)       //循环2^N次，枚举i从000..000到111..111
    Subset(i);
  for(set<string>::iterator ii=s.begin(); ii!=s.end(); ii++)
    cout<<*ii<<endl;
  return 0;
}

