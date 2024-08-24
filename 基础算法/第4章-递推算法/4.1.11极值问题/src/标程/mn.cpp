//极值问题
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("mn.in","r",stdin);
  freopen("mn.out","w",stdout);
  int k,m,m1=1,m2=1,temp;
  scanf("%d",&k);
  while (m2+m1<k)
  {
    m=m1+m2;
    temp=m1;
    m1=m;
    m2=temp;
  }
  printf("%d %d\n",m2,m1);
  return 0;
}

