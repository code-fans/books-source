#include <bits/stdc++.h>
using namespace std;
bool b[10005];

int main()
{
  //freopen("prime2.in","r",stdin);
  //freopen("prime2.out","w",stdout);
  int n;
  scanf("%d",&n);
  for (int i=2; i<=n/2; i++)
    if (!b[i])
      for (int j=2; j*i<=n; j++)
        b[i*j]=true;
  for (int i=2; i+2<=n; i++)
    if (!b[i] && !b[i+2])
      printf("%d %d\n",i,i+2);
  return 0;
}
