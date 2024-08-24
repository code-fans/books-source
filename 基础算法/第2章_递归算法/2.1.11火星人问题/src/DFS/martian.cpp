#include <bits/stdc++.h>
using namespace std;

int cnt,permutation[10001],m,n,a[10001];
bool used[10001];

void Out()
{
  for(int i=1; i<=n; i++)
    cout<<permutation[i]<<(i==n?"\n":" ");
  exit (0);
}

int DFS(int pos)                 //pos为当前位置,从前往后扫描
{
  if(pos>n)
  {
    if(++cnt>m)                 //如果是第m个排列则输出答案
      Out();
  }
  else
    for(int i=a[pos]; i<=n; i++) //从当前数开始枚举到n
      if(!used[i])               //如果当前数没用过
      {
        a[pos]=1;
        permutation[pos]=i;      //排列赋值
        used[i]=true;            //标记该数已使用
        DFS(pos+1);
        used[i]=false;           //恢复该数未使用
      }
}

int main()
{
  freopen("martian.in","r",stdin);
  freopen("martian.out","w",stdout);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  DFS(1);
  return 0;
}
