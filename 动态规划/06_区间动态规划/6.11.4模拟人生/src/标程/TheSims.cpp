//ģ������
#include <bits/stdc++.h>
using namespace std;
int Line[200],n,m,sum[200],Max,Min=0x7fffffff;
int f[200][20];
int g[200][20];

void Dp(int a[])
{
  for(int i=1; i<=n; i++)                          //ǰ���
    sum[i]=sum[i-1]+a[i];
  for(int i=0; i<=n; i++)                          //��ʼ��
    for(int j=0; j<=m; j++)
    {
      f[i][j]=0;
      g[i][j]=0x7fffffff;
    }
  for(int i=1; i<=n; i++)
    f[i][1]=g[i][1]=(sum[i]%10+10)%10;

  f[0][0]=1;
  g[0][0]=1;
  for(int j=2; j<=m; j++)
    for(int i=j; i<=n; i++)
      for(int k=j-1; k<i; k++)
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
    Line[i+n]=Line[i];                             //������չһ��
  }
  for(int i=0; i<n; i++)
    Dp(Line+i);
  printf("%d\n%d\n",Min,Max);
  return 0;
}

