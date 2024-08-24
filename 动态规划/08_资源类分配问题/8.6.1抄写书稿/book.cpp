//Dp
#include <bits/stdc++.h>
using namespace std;
int a[501],d[501];
int f[501][501];//前i个人抄写j本书需要花费的时间
int k,m;

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
  //freopen("book.in","r",stdin);
  //freopen("book.out","w",stdout);
  while(scanf("%d%d",&m,&k)==2)
  {
    if(m==0 && k==0)
    {
      printf("\n");
      continue;
    }
    memset(f,0x3f,sizeof(f));
    for (int j=1; j<=m; j++)
    {
      scanf("%d",&a[j]);
      d[j]=d[j-1]+a[j];//前缀和
      f[1][j]=d[j];
    }
    for (int i=2; i<=k; i++) //第i个人
      for (int j=1; j<=m; j++) //到第j本书结束
        for (int l=1; l<j; l++) //从第l+1本书开始
          f[i][j]=min(f[i][j],max(f[i-1][l],d[j]-d[l]));
    dg(m,k);
  }
  return 0;
}
