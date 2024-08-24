//军事情报
#include <bits/stdc++.h>
using namespace std;

unsigned long long s[1001]= {0,0,1};

int main()
{
  //freopen("intelligence.in","r",stdin);
  //freopen("intelligence.out","w",stdout);
  for (int i=3; i<=1000; i++)
    s[i]=(i-1)*(s[i-1]+s[i-2]);
  int n;
  scanf("%d",&n);
  printf("%llu\n",s[n]);
  return 0;
}

