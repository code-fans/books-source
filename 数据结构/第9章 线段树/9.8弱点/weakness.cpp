#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int n,a[N];
int ans_x, ans_y;

struct node
{
  int r,l;
  int maxx,minn;
} s[N<<2];

void build(int l, int r, int n)
{
  s[n].l = l;
  s[n].r = r;
  s[n].maxx = 0;
  s[n].minn = N;
  if(l == r)
  {
    s[n].maxx = s[n].minn = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, n<<1);
  build(mid + 1, r, n<<1|1);
  s[n].maxx = max(s[n<<1].maxx, s[n<<1|1].maxx);
  s[n].minn = min(s[n<<1].minn, s[n<<1|1].minn);
}
void query(int l, int r, int n)
{
  if(s[n].l == l && s[n].r == r)
  {
    ans_x = max(ans_x, s[n].maxx);
    ans_y = min(ans_y, s[n].minn);
    return;
  }
  int mid = (s[n].l + s[n].r) >> 1;
  if(r <= mid)
    query(l, r, n<<1);
  else if(l > mid)
    query(l, r, n<<1|1);
  else
  {
    query(l, mid, n<<1);
    query(mid+1, r, n<<1|1);
  }
}

int main()
{
  freopen("weakness.in","r",stdin);
  freopen("weakness.out","w",stdout);
  int m,t,i,x,y;
  while(~scanf("%d%d",&m,&t))
  {
    for(i = 1; i <= m; i ++)
      scanf("%d",&a[i]);
    build(1,m,1);
    while(t--)
    {
      scanf("%d%d",&x,&y);
      ans_x = 0;
      ans_y = N;
      query(x,y,1);
      printf("%d\n",ans_x-ans_y);
    }
  }
  return 0;
}

