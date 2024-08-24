#include <bits/stdc++.h>
using namespace std;
const int MAXN=50005;
#define LL long long

struct MAT
{
  int x,y;
} a[MAXN];

int n,tot,l,r;
LL x[MAXN],y[MAXN],q[MAXN],f[MAXN];

bool Cmp(MAT A,MAT B)
{
  return A.x!=B.x?A.x<B.x:A.y<B.y;
}

double Slope(int k,int j)
{
  return (double)(f[j]-f[k])/(y[k+1]-y[j+1]);
}

int main()
{
  //freopen("Land.in","r",stdin);
  //freopen("Land.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d%d",&a[i].x,&a[i].y);
  sort(a+1,a+n+1,Cmp);
  for(int i=1; i<=n; i++)         //单调队列
  {
    while(tot && a[i].y>=y[tot])
      tot--;
    x[++tot]=a[i].x;
    y[tot]=a[i].y;
  }
  for(int i=1; i<=tot; i++)
  {
    while(l<r && Slope(q[l],q[l+1])<x[i])
      l++;
    int t=q[l];
    f[i]=f[t]+x[i]*y[t+1];
    while(l<r && Slope(q[r],i)<Slope(q[r-1],q[r]))
      r--;
    q[++r]=i;
  }
  printf("%lld",f[tot]);
  return 0;
}
