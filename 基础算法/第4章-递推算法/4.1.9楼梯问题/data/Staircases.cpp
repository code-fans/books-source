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
    f[i][i]=1;                    //把i划分，最大数为i，方案数显然为1

  for(int i=2; i<=n; i++)//枚举数n
    for(int j=1; j<i; j++)             //枚举j
      for(int k=1; k<=min(i-j,j-1); k++)//k小于等于j-1,但也要小于i-j
        f[i][j]+=f[i-j][k];
  for(int i=1; i<n; i++)
    sum+=f[n][i];
  printf("%lld\n",sum);
  return 0;
}

