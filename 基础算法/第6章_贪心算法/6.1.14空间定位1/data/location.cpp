//时空定位1
#include<bits/stdc++.h>
using namespace std;

double dot[605];

int main()
{
  freopen("location.in", "r", stdin);
  freopen("location.out", "w", stdout);
  int m, n;
  scanf("%d",&m);
  for (int i=1; i<=m; i++)
  {
    scanf("%d", &n);
    for (int k=1; k<=n; k++)
      scanf("%lf", &dot[k]);
    sort(dot+1, dot+n+1, greater<double>());
    double len=0;
    for (int j=1; j<=n; j++)
    {
      len+=2*(sqrt(dot[j]*dot[j]-1));     //覆盖的总长度
      if (len>=20)
      {
        printf("%d\n", j);
        break;
      }
    }
  }
  return 0;
}

