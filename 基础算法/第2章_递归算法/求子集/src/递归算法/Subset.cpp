//求子集 - 递归算法
#include <bits/stdc++.h>
using namespace std;

int n;
int a[26+1];               //用01来标记，即用N位01对应1个N位二进制数并枚举

void print()
{
  printf("(");
  for(int i=1; i<=n; i++)
    if(a[i]==1)
      printf("%c ",char('a'+i-1));
  printf(")\n");
}

void Try(int digit)
{
  for(int i=0; i<=1; i++)  //穷举所有的0，1组合
  {
    a[digit]=i;
    if(digit==n)
      print();
    else
      Try(digit+1);
  }
}

int main()
{
  freopen("Subset.in","r",stdin);
  freopen("Subset.out","w",stdout);
  scanf("%d",&n);
  Try(1);
  return 0;
}

