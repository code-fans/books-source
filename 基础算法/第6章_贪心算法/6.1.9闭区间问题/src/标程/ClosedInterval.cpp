#include <bits/stdc++.h>
using namespace std;

struct node
{
  int s,e;
} qu[40010];

bool Cmp(node a,node b)
{
  return a.e<b.e;
}

int main()
{
  //freopen("ClosedInterval.in","r",stdin);
  //freopen("ClosedInterval.out","w",stdout);
  int n;
  while(scanf("%d",&n)==1)
  {
    for(int i=0; i<n; i++)
    {
      scanf("%d%d",&qu[i].s,&qu[i].e);
      if(qu[i].s>qu[i].e)
        swap(qu[i].s,qu[i].e);
    }
    sort(qu,qu+n,Cmp);
    int ans=0;
    int cur=qu[0].e;
    for(int i=1; i<n; i++)
      if(qu[i].s<=cur)  //注意题目问的是去掉尽可能少的区间数使不相交
        ans++;          //所以相交的就删除
      else
        cur=qu[i].e;
    printf("%d\n",ans);
  }
  return 0;
}

