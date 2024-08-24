//猴子吃桃的递归解决
#include <bits/stdc++.h>
using namespace std;
int n;

int peach(int day)
{
  if(day==n)
    return 1;
  else
    return 2*(peach(++day)+1);
}

int main()
{
  freopen("peach.in","r",stdin);
  freopen("peach.out","w",stdout);
  cin>>n;
  cout<<peach(1)<<endl;
  return 0;
}
