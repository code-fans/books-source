//抄近路
#include <bits/stdc++.h>
using namespace std;

int x,y,n,f[1005],longest;
struct p
{
  int x,y;
} P[1000005];

bool Cmp(p a,p b)
{
  return a.y<b.y;
}

int main ()
{
  freopen("shortline.in","r",stdin);
  freopen("shortline.out","w",stdout);
  scanf("%d%d%d",&x,&y,&n);
  for (int i=0; i<n; i++)
    scanf("%d%d",&P[i].x,&P[i].y);
  sort(P,P+n,Cmp);
  for (int i=0; i<n; i++)
  {
    f[i]=1;
    for (int j=0; j<i; j++)
      if (P[j].x<P[i].x && P[j].y<P[i].y && f[i]<f[j]+1)
        f[i]=f[j]+1;
    longest=max(f[i],longest);                  //更新最长不下降子序列
  }
  cout<<int(100*((x+y-2*longest)+longest*sqrt(2))+0.5)<<'\n';
  return 0;
}

