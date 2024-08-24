//数的划分 —DFS
#include <bits/stdc++.h>
using namespace std;

int n,k,cnt;

void DFS(int cur,int k,int n)//刚划走了cur份 
{
  if(k==0)
  {
    if(n==0)
      cnt++;
  }
  else
    for(int i=n/k; i>=cur; i--)         //优化
      DFS(i,k-1, n-i);
}

int main()
{
  freopen("Numdismantle.in","r",stdin);
  freopen("Numdismantle.out","w",stdout);
  scanf("%d%d",&n,&k);
  DFS(1,k,n);
  printf("%d\n",cnt);
}
