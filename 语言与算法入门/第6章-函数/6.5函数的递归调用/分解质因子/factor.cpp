//分解质因子
#include <bits/stdc++.h>
using namespace std;
bool first=true;

void factor(int n,int p)
{
  if(n>1)
    if(n%p==0)
    {
      first?printf("%d",p),first=false:	printf(" %d",p);
      factor(n/p,p);
    }
    else
      factor(n,p+1);
}

int main()
{
  //freopen("factor.in","r",stdin);
  //freopen("factor.out","w",stdout);
  int n;
  scanf("%d",&n);
  factor(n,2);
  printf("\n");
  return 0;
}
