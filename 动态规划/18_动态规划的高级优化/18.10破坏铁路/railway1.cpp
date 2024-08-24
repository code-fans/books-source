//破坏铁路 四边形不等式 
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long inf,sum[1010],sqsum[1010],f[2][1010],s[2][1010];

int getw(int i,int j)
{
  return ((sum[j]-sum[i-1])*(sum[j]-sum[i-1])-(sqsum[j]-sqsum[i-1]))>>1;
}

int main()
{
  freopen("railway.in","r",stdin);
  freopen("railway.out","w",stdout);
  inf=2000000000;
  inf*=1000000000;
  while(scanf("%d%d",&n,&m)&&n)
  {
    m++;
    sum[0]=sqsum[0]=0;
    for(int i=1,a; i<=n; i++)
    {
      scanf("%d",&a);
      sum[i]=sum[i-1]+a;
      sqsum[i]=sqsum[i-1]+a*a;
    }

    int past=0,now=1;
    for(int i=1; i<=n; i++) f[past][i]=inf,s[past][i]=1;
    f[past][0]=0;
    for(int i=1; i<=m; i++)
    {
      s[now][n+1]=n;
      for(int j=n; j>=i; j--)
      {
        f[now][j]=inf;
        for(int k=s[past][j]; k<=s[now][j+1]; k++)
          if (f[now][j]>=f[past][k-1]+getw(k,j))
          {
            f[now][j]=f[past][k-1]+getw(k,j);
            s[now][j]=k;
          }
      }
      swap(past,now);
    }
    printf("%lld\n",f[past][n]);
  }
  return 0;
}

