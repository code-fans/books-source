//数字三角形 - 动规
#include <bits/stdc++.h>
using namespace std;

int F[1001][1001];

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=i; j++)
      scanf("%d",&F[i][j]);
  for(int i=n-1; i>=1; i--)                         //动规
    for(int j=1; j<=i; j++)
      F[i][j]+=max(F[i+1][j],F[i+1][j+1]);
  printf("%d\n",F[1][1]);
  return 0;
}

