//合唱团
//正反LIS后寻找最值
#include<bits/stdc++.h>
using namespace std;
int T[201];
int f[201],g[201];

int main()
{
  //freopen("chorus.in","r",stdin);
  //freopen("chorus.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&T[i]);
  for(int i=1; i<=n; i++)
  {
    f[i]=1;
    for(int j=1; j<=i-1; j++)
      if(T[j]<T[i]&&f[j]+1>f[i])
        f[i]=f[j]+1;
  }
  for(int i=n; i>=1; i--)
  {
    g[i]=1;
    for(int j=i+1; j<=n; j++)
      if(T[j]<T[i]&&g[j]+1>g[i])
        g[i]=g[j]+1;
  }
  int Min=n;
  for(int k=1; k<=n; k++)
    Min=min(n-f[k]-g[k]+1,Min);
  printf("%d\n",Min);
}
