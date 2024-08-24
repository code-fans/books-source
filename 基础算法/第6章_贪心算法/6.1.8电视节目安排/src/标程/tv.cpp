//电视节目安排
#include <bits/stdc++.h>
using namespace std;

struct T
{
  int s, e;
} Ti[105];

int Cmp( T a, T b)
{
  return a.e < b.e;
}

int main()
{
  freopen("tv.in","r",stdin);
  freopen("tv.out","w",stdout);
  int n;
  while(scanf("%d", &n), n)
  {
    for(int i=0; i<n; i++)
      scanf("%d%d",&Ti[i].s,&Ti[i].e);
    sort(Ti,Ti+n,Cmp);                        //以区间末坐标排序
    int cur=Ti[0].e;
    int ans=1;
    for(int i=1; i<n; i++)
      if(Ti[i].s>=cur)                    //选不相交的
      {
        cur=Ti[i].e;
        ans++;
      }
    printf("%d\n", ans);
  }
  return 0;
}

