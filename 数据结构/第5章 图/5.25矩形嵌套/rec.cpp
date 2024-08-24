//¾ØÐÎÇ¶Ì×
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int Map[MAXN][MAXN],d[MAXN];
int n;
struct Node
{
  int l,r;
} a[MAXN];

int dp(int i)
{
  int &ans=d[i];
  if(ans>0) return ans;
  ans=1;
  for(int j=1; j<=n; j++)
    if(Map[i][j]) ans=max(ans,dp(j)+1);
  return ans;
}

int main()
{
  freopen("rec.in","r",stdin);
  freopen("rec.out","w",stdout);
  int Case;
  scanf("%d",&Case);
  while(Case--)
  {
    memset(d,0,sizeof(d));
    memset(Map,0,sizeof(Map));
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
      scanf("%d %d",&a[i].l,&a[i].r);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        if((a[j].l>a[i].l&&a[j].r>a[i].r)||(a[j].l>a[i].r&&a[j].r>a[i].l))
          Map[i][j]=1;
    int ans=-1;
    for(int i=1; i<=n; i++)
      ans=max(ans,dp(i));
    printf("%d\n",ans);
  }
}
