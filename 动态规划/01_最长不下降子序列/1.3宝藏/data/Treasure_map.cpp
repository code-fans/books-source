//±¦²Ø ¡ª ¶þ·Ö
#include <bits/stdc++.h>
using namespace std;

int f[100010],n,m,p;
struct node
{
  int x,y;
  bool operator<(const node &b)const
  {
    return x!=b.x ? x<b.x : y<b.y;
  }
} T[100010];

int HalfFind(node num,int l,int r)
{
  while(l<=r)
  {
    int mid=(l+r)>>1;
    if(T[f[mid]].y>num.y)
      l=mid+1;
    else
      r=mid-1;
  }
  return l-1;
}

int main()
{
  //freopen("Treasure_map.in","r",stdin);
  //freopen("Treasure_map.out","w",stdout);
  scanf("%d %d %d",&n,&m,&p);
  for(int i=1; i<=p; i++)
    scanf("%d %d",&T[i].x,&T[i].y);
  f[1]=1;
  int longest=1;
  sort(T+1,T+1+p);
  for(int i=2; i<=p; i++)
  {
    if(T[i].y<T[f[longest]].y)
      f[++longest]=i;
    else
    {
      int pos=HalfFind(T[i],1,longest);
      f[pos+1]=i;
    }
  }
  printf("%d\n",longest);
  return 0;
}
