#include<bitsdc++.h>
using namespace std;
const int MAXN=100005,p1=39989,p2=1000000000;
double k[MAXN],b[MAXN];
int lcnt,q,op,xa,ya,xb,yb;
struct tree
{
  int l,r,v;
} tr[MAXN<<2];
void build(int num=1,int l=1,int r=p1)
{
  tr[num].l=l;
  tr[num].r=r;
  tr[num].v=0;
  if(l==r)return;
  const int mid=l+r>>1;
  return build(num<<1,l,mid),build(num<<1|1,mid+1,r);
}
double f(int x,int y)
{
  return k[y]*x+b[y];
}
void update(int num,int l,int r,int x)
{
  if(l<=tr[num].l&&tr[num].r<=r)
  {
    const int mid=tr[num].l+tr[num].r>>1;
    if(f(mid,x)>f(mid,tr[num].v))swap(x,tr[num].v);
    if(tr[num].l==tr[num].r)return;
    if(f(tr[num].l,x)>f(tr[num].l,tr[num].v))return update(num<<1,l,r,x);
    if(f(tr[num].r,x)>f(tr[num].r,tr[num].v))return update(num<<1|1,l,r,x);
    return;
  }
  const int ls=num<<1,rs=ls|1;
  if(l<=tr[ls].r)update(ls,l,r,x);
  if(tr[rs].l<=r)update(rs,l,r,x);
}
int get_cmp(int x,int y,int z)
{
  return f(x,y)>f(x,z)?y:z;
}
int query(int num,int x)
{
  if(tr[num].l==tr[num].r) return tr[num].v;
  if(x<=tr[num<<1].r)return get_cmp(x,tr[num].v,query(num<<1,x));
  return get_cmp(x,tr[num].v,query(num<<1|1,x));
}
int ans;
void get_mod(int&x,int mod)
{
  x=(x-1ll+ans)%mod+1;
}
int main()
{
  scanf("%d",&q),build(),b[0]=-1e9;
  while(q--)
  {
    scanf("%d%d",&op,&xa),get_mod(xa,p1);
    if(op)
    {
      scanf("%d%d%d",&ya,&xb,&yb);
      get_mod(ya,p2),get_mod(xb,p1),get_mod(yb,p2),++lcnt;
      if(xa==xb)
      {
        k[lcnt]=0.0;
        b[lcnt]=double(max(ya,yb));
      }
      else
      {
        k[lcnt]=double(yb-ya)/(xb-xa);
        b[lcnt]=ya-k[lcnt]*xa;
      }
      update(1,min(xa,xb),max(xa,xb),lcnt);
    }
    else
    {
      printf("%d\n",ans=query(1,xa));
    }
  }
  return 0;
}
