//数列极差问题
#include <bits/stdc++.h>
using namespace std;
#define MAX 0x7fffffff

bool Cmp (const int a, const int b)
{
  return a > b;
}

int main()
{
  //freopen("Max_Min.in","r",stdin);
  //freopen("Max_Min.out","w",stdout);
  int n, a[50001], b[50001];
  while (scanf("%d", &n) == 1 && n)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      b[i]=a[i];
    }
    for(int k=1; k<n; k++)
    {
      sort(a, a+n);
      a[1]=a[0]*a[1]+1;
      a[0]=MAX;
    }
    for(int k=1; k<n; k++)
    {
      sort(b, b+n, Cmp);
      b[1]=b[0]*b[1]+1;
      b[0]=0;
    }
    printf("%0.lf\n", fabs(a[1]-b[1]));
  }
  return 0;
}
