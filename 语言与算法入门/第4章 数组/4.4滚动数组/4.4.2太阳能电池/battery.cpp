//Ì«ÑôÄÜµç³Ø
#include <bits/stdc++.h>
using namespace std;
#define F(i) f[(i)%3]

int main()
{
  //freopen("battery.in","r",stdin);
  //freopen("battery.out","w",stdout);
  int n;
  int f[3]= {1,1};
  scanf("%d",&n);
  for(int i=2; i<=n; i++)
    F(i)=(F(i-1)+F(i-2)*2)%12345;
  printf("%d\n",F(n));
  return 0;
}

