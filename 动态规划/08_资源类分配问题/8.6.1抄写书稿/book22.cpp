//Dp
#include <bits/stdc++.h>
using namespace std;
int a[501],d[501];
int f[501][501];
int k,m;
int max(int a,int b)
{
  return a>b?a:b;
}
int min(int a,int b)
{
  return a<b?a:b;
}
void dg(int i,int j)
{
  if (j==0) return;
  if (j==1)
  {
    printf("1 %d\n",i);
    return;
  }
  int t=i,x=a[i];
  while (x+a[t-1]<=f[k][m])
  {
    x+=a[--t];
  }
  dg(t-1,j-1);
  printf("%d %d\n",t,i);
}
int main()
{
  freopen("book.in","r",stdin);
  freopen("book.out","w",stdout);
  while(scanf("%d%d",&m,&k)!=EOF)
  {
    if(m==0&&k==0)
    {
      printf("\n");
      continue;
    }
    memset(f,0x3f,sizeof(f));
    int i,j,l;
    for (j=1; j<=m; j++)
    {
      scanf("%d",&a[j]);
      d[j]=d[j-1]+a[j];
      f[1][j]=d[j];
    }
    for (i=2; i<=k; i++) //��i����
      for (j=1; j<=m; j++) //����j�������
        for (l=1; l<j; l++) //�ӵ�l+1���鿪ʼ
          f[i][j]=min(f[i][j],max(f[i-1][l],d[j]-d[l]));
    dg(m,k);
  }
  return 0;
}
