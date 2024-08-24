//选班级代表
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int Class,Score;//Class的首字母不能小写，因为class是C++的关键字
  cin>>Class>>Score;
  if(Class ==1)
    if(Score >90 )
      cout<<"Yes\n";
    else
      cout<<"No\n";
  else
    cout<<"No\n";
  return 0;
}

