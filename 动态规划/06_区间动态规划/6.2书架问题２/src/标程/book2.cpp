//�������2
#include <bits/stdc++.h>
using namespace std;

struct book
{
  int height,wide;
} a[200];
int f[200][200];

bool Cmp(const book &a,const book &b)
{
  return a.height<b.height;
}

int main()
{
  //freopen("book2.in","r",stdin);
  //freopen("book2.out","w",stdout);
  int n,k;
  scanf("%d%d",&n,&k);
  for (int i=1; i<=n; ++i)
    scanf("%d%d",&a[i].height,&a[i].wide);
  sort(a+1,a+n+1,Cmp);                     //���߶��ź���
  for(int i=1; i<=n; ++i)                  //���δ���ÿһ����
    for(int j=2; j<=min(i,n-k); ++j)       //ö��ѡj����
    {
      f[i][j]=0x3f3f3f3f;
      for(int x=j-1; x<i; ++x)
        f[i][j]=min(f[i][j],f[x][j-1]+abs(a[x].wide-a[i].wide));
    }
  int ans=f[n][n-k];
  for(int i=n-1; i>=n-k; --i)
    ans=min(ans,f[i][n-k]);
  printf("%d\n",ans);
  return 0;
}


