//Dp
#include <bits/stdc++.h>
using namespace std;
int a[501],d[501];
int f[501][501];//ǰi���˳�дj������Ҫ���ѵ�ʱ��
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
      d[j]=d[j-1]+a[j];//ǰ׺��
      f[1][j]=d[j];
    }
    for (int i=2; i<=k; i++) //��i����
      for (int j=1; j<=m; j++) //����j�������
        for (int l=1; l<j; l++) //�ӵ�l+1���鿪ʼ
          f[i][j]=min(f[i][j],max(f[i-1][l],d[j]-d[l]));
    dg(m,k);
  }
  return 0;
}
