//模拟人生
#include <bits/stdc++.h>
using namespace std;

int Line[200],n,m,sum[200],Max,Min=0x7fffffff;
int f[200][20],g[200][20];

void Dp(int a[])
{
  for(int i=1; i<=n; i++)                          //前序和
    sum[i]=sum[i-1]+a[i];
  memset(f,0,sizeof(f));
  memset(g,127,sizeof(g));
  for(int i=1; i<=n; i++)
    f[i][1]=g[i][1]=(sum[i]%10+10)%10;
  f[0][0]=1;
  g[0][0]=1;
  for(int j=2; j<=m; j++)                          //枚举分区
    for(int i=j; i<=n; i++)                        //枚举数字
      for(int k=j-1; k<i; k++)                     //枚举断点
      {
        f[i][j]=max(f[i][j],f[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
        g[i][j]=min(g[i][j],g[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
      }
  Max=max(Max,f[n][m]);
  Min=min(Min,g[n][m]);
}

int main()
{
  //freopen("TheSims.in","r",stdin);
  //freopen("TheSims.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&Line[i]);
    Line[i+n]=Line[i];                             //破环为链
  }
  for(int i=0; i<n; i++)
    Dp(Line+i);
  printf("%d\n%d\n",Min,Max);
  return 0;
}

