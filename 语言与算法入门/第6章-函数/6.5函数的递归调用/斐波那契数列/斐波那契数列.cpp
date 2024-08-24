//ì³²¨ÄÇÆõÊıÁĞ
#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
  if(n<3)
    return 1;
  return f(n-1)+f(n-2);
}

int main()
{
  int n;
  scanf("%d",&n);
  printf("%d",f(n));
  return 0;
}

