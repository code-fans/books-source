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
    f[i][i]=1;                    //��i���֣������Ϊi����������ȻΪ1

  for(int i=2; i<=n; i++)//ö����n
    for(int j=1; j<i; j++)             //ö��j
      for(int k=1; k<=min(i-j,j-1); k++)//kС�ڵ���j-1,��ҲҪС��i-j
        f[i][j]+=f[i-j][k];
  for(int i=1; i<n; i++)
    sum+=f[n][i];
  printf("%lld\n",sum);
  return 0;
}

