//子串包含问题
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("substr.in","r",stdin);
  //freopen("substr.out","w",stdout);
  string s1,s2;
  cin>>s1>>s2;
  if(s1.size()<s2.size())     //比较两字符串长度，将长字符串放在前面
    swap(s1,s2);
  s1+=s1;                     //复制s1
  cout<<(s1.find(s2)==-1?"No":"Yes")<<'\n';
  return 0;
}

