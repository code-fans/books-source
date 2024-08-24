#include<bits/stdc++.h>
using namespace std;

map<int,int>fa;
map<int,int>cnt;

int findfather(int v)
{
  if(fa[v]==0||fa[v]==v)
    return fa[v]=v;
  int pp=findfather(fa[v]);
  cnt[v]=cnt[v]+cnt[fa[v]];
  cnt[v]&=1;
  fa[v]=pp;
  return pp;
}
int main()
{
  int x,n;
  cin>>x>>n;
  for(int i=1; i<=n; i++)
  {
    int p,q;
    char r[15]= {0};
    scanf("%d%d%s",&p,&q,r);
    q++;
    int flg=1;
    if(r[0]=='e')flg=0;
    int p1=findfather(p),q1=findfather(q);
    if(p1==q1)
    {
      if(cnt[p]!=((cnt[q]+flg)&1))printf("%d\n",i-1);
      else continue;
      return 0;
    }
    else
    {
      cnt[q1]=(cnt[q]!=flg);
      fa[q1]=p;
    }
  }
  printf("%d\n",n);
  return 0;
}
