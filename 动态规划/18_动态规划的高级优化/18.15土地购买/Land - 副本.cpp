#include<cstdio>
#include<algorithm>
#define ll long long
#define DB double
using namespace std;
ll read()
{
  register ll x=0;
  bool f=1;
  register char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')f=0;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return f?x:-x;
}
const int N=5e4+10;
struct node
{
  int x,y;
  bool operator < (const node &b)const
  {
    return x==b.x?y<b.y:x<b.x;
  }
} a[N];
ll x[N],y[N],f[N];
int n,tot,q[N];
DB slop(int a,int b)
{
  return (DB)(f[b]-f[a])/(y[a+1]-y[b+1]);
}
int main()
{
  freopen("Land5.in","r",stdin);
  freopen("Land5.ans","w",stdout);

  n=read();
  for(int i=1; i<=n; i++)
    a[i].x=read(),a[i].y=read();
  sort(a+1,a+n+1);
  for(int i=1; i<=n; i++)
  {
    for(; tot&&a[i].y>=y[tot]; tot--);
    x[++tot]=a[i].x;
    y[tot]=a[i].y;
  }
  int l=0,r=0;
  for(int i=1; i<=tot; i++)
  {
    for(; l<r&&slop(q[l],q[l+1])<x[i]; l++);
    f[i]=f[q[l]]+y[q[l]+1]*x[i];
    for(; l<r&&slop(q[r],i)<slop(q[r-1],q[r]); r--);
    q[++r]=i;
  }
  printf("%lld",f[tot]);
  return 0;
}
