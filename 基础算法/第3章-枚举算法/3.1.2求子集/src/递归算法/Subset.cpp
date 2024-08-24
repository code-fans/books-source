//求子集 - 递归算法
#include <bits/stdc++.h>
using namespace std;

int n;
int a[27];               //用01来标记，即用N位01对应1个N位二进制数并枚举
set <string> s;

void Subset()
{
  string str="(";
  for(int i=0; i<N; i++)
    if((1<<i)&n)
      str+=char(i+'a');
  s.insert(str+")");
}

void DFS(int digit)        //digit表示当前位置 
{
  for(int i=0; i<=1; i++)  //穷举所有的0，1组合
  {
    a[digit]=i;
    if(digit==n)
      Subset();
    else
      DFS(digit+1);
  }
}

int main()
{
  //freopen("Subset.in","r",stdin);
  //freopen("Subset.out","w",stdout);
  scanf("%d",&n);
  DFS(1);
  for(set<string>::iterator ii=s.begin(); ii!=s.end(); ii++)
    cout<<*ii<<endl;
  return 0;
}

