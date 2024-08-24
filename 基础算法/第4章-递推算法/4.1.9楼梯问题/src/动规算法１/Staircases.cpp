//楼梯问题 - 动规算法1
#include <bits/stdc++.h>
using namespace std;

long long f[501][501];

int main()
{
  //freopen("Staircases.in","r",stdin);
  //freopen("Staircases.out","w",stdout);
  int n;
  long long sum=0;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    f[i][i]=1;
  for(int i=1; i<=n; i++)
    for(int j=1; j<i; j++)
      for(int k=1; k<=min(i-j,j-1); k++)
        if(i-j>=k)
          f[i][j]+=f[i-j][k];
  for(int i=1; i<n; i++)
    sum+=f[n][i];
  printf("%lld\n",sum);
  return 0;
}

