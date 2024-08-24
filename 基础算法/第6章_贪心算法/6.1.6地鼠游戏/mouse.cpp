//地鼠游戏
#include <bits/stdc++.h>
using namespace std;

inline int Read()
{
  int x=0,f=1;
  char c=getchar();
  for(; c<'0' || c>'9'; c=getchar())
    if(c=='-')
      f=-1;
  for(; c>='0'&&c<='9'; c=getchar())
    x=x*10+c-'0';
  return x*f;
}

struct st
{
  int t,v;
} mouse[1000005];

bool Cmp(st a,st b)
{
  return a.t>b.t;
}

int main()
{
  freopen("mouse.in","r",stdin);
  freopen("mouse.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  priority_queue<int> q;               //优先队列默认从大到小保存数据
  long long ans=0,n,now=0;
  n=Read();
  for(int i=0; i<n; i++)
    mouse[i].t=Read();
  for(int i=0; i<n; i++)
    mouse[i].v=Read();
  sort(mouse,mouse+n,Cmp);             //按时间从大到小排
  for(int tim=mouse[0].t; tim>0; tim--)//从最多的停留时间的地鼠开始
  {
    for(; mouse[now].t==tim; now++)    //把等于当前时间的加入
      q.push(mouse[now].v);
    if(!q.empty())
      ans+=q.top(),q.pop();            //每次取价值最大的，队列内的肯定都满足时间要求
  }
  cout<<ans<<endl;
  return 0;
}

