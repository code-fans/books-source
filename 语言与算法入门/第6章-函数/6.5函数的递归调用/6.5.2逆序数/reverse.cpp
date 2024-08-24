//ÄæĞòÊı
#include <bits/stdc++.h>
using namespace std;

int Turn(int n)
{
  if(n>=10)
  {
    printf("%d",n%10);
    Turn(n/10);
  }
  else
    printf("%d",n);
}

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  int n;
  scanf("%d",&n);
  Turn(n);
  printf("\n");
  return 0;
}

