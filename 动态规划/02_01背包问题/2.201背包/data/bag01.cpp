//01±³°üÓÅ»¯
#include <bits/stdc++.h>
using namespace std;

int f[10001];

int main()
{
  freopen("bag01.in","r",stdin);
  freopen("bag01.out","w",stdout);
  int m,n,w,c;
  scanf("%d%d",&m,&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d%d",&w,&c);
    for(int j=m; j>=w; --j)
      f[j]=max(f[j-w]+c,f[j]);
  }
  printf("%d\n",f[m]);
  return 0;
}

