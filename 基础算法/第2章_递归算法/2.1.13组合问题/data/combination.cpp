//组合问题
#include<bits/stdc++.h>
using namespace std;

int m,n;
int a[101];


void DFS(int i)
{
  if(i>n)
  {
    for(int i=1; i<=n; i++)
      cout<<a[i];
    cout<<endl;
  }
  else
    for(int j=a[i-1]+1; j<=m; j++)//枚举每一个可能的数，该数不小于前一数
    {
      a[i]=j;     //当前位存入j
      DFS(i+1);   //继续下一位递归
      a[i]=0;
    }
}

int main()
{
  //freopen("combination.in","r",stdin);
  //freopen("combination.out","w",stdout);
  cin>>m>>n;
  DFS(1);
  return 0;
}
