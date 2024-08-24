//广告问题2
//尽量在重叠区贴广告，而重叠位置一定在区间尾部
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int s, e, t;
} a[5001];
int used[300001];

bool Cmp(node a, node b)
{
  return a.e < b.e;
}

int main()
{
  freopen("ad2.in","r",stdin);
  freopen("ad2.out","w",stdout);
  int n, w,ans=0;
  scanf("%d%d", &n, &w);
  for(int i=1; i<=w; i++)
    scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].t);
  sort(a+1, a+w+1, Cmp);             //按结束位置排序
  for(int i=1; i<=w; i++)
  {
    int ad = 0;
    for(int j=a[i].s; j<=a[i].e; j++)//统计该区域的广告数
      if(used[j])
        ad++;
    if(ad >= a[i].t)                 //如果广告已超过要求的数，则跳过
      continue;
    for(int j=a[i].e; j>=a[i].s && ad!=a[i].t; j--)//否则由后向前扫描
      if(!used[j])
      {
        used[j]=1;                   //添加缺少的广告
        ad++;
        ans++;
      }
  }
  printf("%d\n", ans);
  return 0;
}
