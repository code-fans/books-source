//6个数排列出所有组合
#include <bits/stdc++.h>
using namespace std;

int f[10];

void Dfs(int k,int n)
{
  if(k>5)
  {
    for(int i=1; i<=5; i++)
      cout<<f[i]<<' ';
    cout<<endl;
  }
  else
    for(int i=f[k-1]+1; i<=n; i++)
    {
      f[k]=i;
      Dfs(k+1,n);
    }
}

int main()
{
  Dfs(1,8);
  return 0;
}

