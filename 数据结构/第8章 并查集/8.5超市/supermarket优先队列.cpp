//优先队列
#include<bits/stdc++.h>
using namespace std;

int n, t,const int maxn = 1e4+100;

struct node
{
  int p,d;
  bool friend operator < (node a,node b) ///优先队列利润小排前面，因为它是最需要替换的（替换后利润更大）
  {
    return a.p>b.p;
  }
} t[maxn];

bool cmp(node x,node y) ///天数是第一关键词，利润是第二关键词
{
  return x.d<y.d||(x.d == y.d && x.p>y.p);
}
int main()
{
  int n;
  while(~scanf("%d",&n))
  {
    priority_queue<node>Q;
    for(int i = 1; i <= n; i++)
      cin>>t[i].p>>t[i].d ;
    sort(t+1,t+1+n,cmp);
    for(int i = 1; i <= n; i++)
      if(t[i].d>Q.size())///当前商品天数大于维护的队列，直接入队（在当前状态下它肯定可选）
        Q.push(t[i]);
      else if(t[i].d == Q.size())///当前商品的天数等于维护的队列，看队头是不是利润更小
        if(t[i].p>Q.top().p)//替换了
          Q.pop(),Q.push(t[i]);
    int ans = 0;
    while(!Q.empty())
      ans+=Q.top().p,Q.pop();
    printf("%d\n",ans);
  }
  return 0;
}
