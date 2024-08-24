//货币系统问题
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("money.in","r",stdin);
  //freopen("money.out","w",stdout);
  int v,n,p;
  scanf("%d%d",&v,&n);
  int f[1001]= {1};
  for(int i=1; i<=v; i++)
  {
    scanf("%d",&p);
    for(int j=p; j<=n; j++)
      f[j]+=f[j-p];
  }
  printf("%d\n",f[n]);
  return 0;
}

