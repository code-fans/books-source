//流水作业调度问题
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

struct node
{
  int x,y;
} a[MAXN],b[MAXN],c[MAXN];

bool cmp1(const node &p, const node &q)
{
  return p.x < q.x;
}

bool cmp2(const node &p, const node &q)
{
  return p.y > q.y;
}

int main()
{
  freopen("flowshop.in","r",stdin);
  freopen("flowshop.out","w",stdout);
  int n;
  while(scanf("%d",&n) && n)
  {
    for(int i=0; i<n; ++i)
      scanf("%d%d",&a[i].x,&a[i].y);
    int len1 = 0, len2 = 0;
    for(int i=0; i<n; ++i)
      if(a[i].x < a[i].y)
      {
        b[len1].x = a[i].x;               //子集1 x<y
        b[len1++].y = a[i].y;
      }
      else
      {
        c[len2].x = a[i].x;               //子集2
        c[len2++].y = a[i].y;
      }
    sort(b,b+len1,cmp1);                  //子集1作业顺序：x不减
    sort(c,c+len2,cmp2);                  //子集2作业顺序：y不增
    for(int i = len1; i<len1+len2; ++i)   //合并两子集
      b[i] = c[i-len1];
    int s1sum[MAXN] = {0};
    for(int i=0; i<n; ++i)                //计算M1花费的时间
      s1sum[i+1] = s1sum[i]+b[i].x;
    int sum = 0;
    for(int i=0; i<n; ++i)                //计算M2花费的时间
      if(sum<s1sum[i+1])                  //要等到M1完成才能开始M2
        sum = s1sum[i+1]+b[i].y;
      else
        sum+=b[i].y;
    printf("%d\n",sum);
  }
  return 0;
}

