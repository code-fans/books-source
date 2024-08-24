//递归—相当于把N划分有多少种方案
#include<bits/stdc++.h>
using namespace std;

int t,cnt;

void Dfs(int limit,int apple,int dish)
{
  if(apple==0)
    cnt++;
  else
    for(int i=limit; i<=apple; i++)
      if(dish>0 && apple-i>=0)
        Dfs(i,apple-i,dish-1);
}

int main()
{
  freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);
  cin>>t;
  for(int i=1; i<=t; i++)
  {
    cin>>m>>n;
    cnt=0;
    Dfs(1,m,n);
    cout<<cnt<<endl;
  }
  return 0;
}
