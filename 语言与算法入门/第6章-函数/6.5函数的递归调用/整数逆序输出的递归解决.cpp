//整数逆序输出的递归解决
#include <bits/stdc++.h>
using namespace std;

int turn(int n)
{
  if(n>=10)
  {
    printf("%d",n%10);
    turn(n/10);
  }
  else
    printf("%d",n);
}

int main()
{
  int n;
  scanf("%d",&n);
  turn(n);
  printf("\n");
  return 0;
}

