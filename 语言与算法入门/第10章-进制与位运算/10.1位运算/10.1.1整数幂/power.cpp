//整数幂-位运算法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  int n,t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    if((n&(n-1))==0)//"=="比"&"优先级高
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}

