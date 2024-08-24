//钓鱼
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int ID,fish,d,time;
  bool operator <(const node &y) const
  {
    return (fish==y.fish?ID>y.ID:fish<y.fish);
  }
} fish[30];
int n,h,ans[30],maxsum;

void GetFish(int h)
{
  maxsum=-1;
  for(int i=0; i<n; i++)
  {
    priority_queue <node> q;
    for(int j=0; j<=i; j++)
      q.push(fish[j]);
    int sum=0;
    int f[30]= {0};
    for(int RealTime=h-fish[i].time; RealTime>0; RealTime-=5)
    {
      node t=q.top();
      if(t.fish==0)          //钓不上鱼了,退出
      {
        f[t.ID]+=RealTime;   //剩下的时间全部用掉
        break;
      }
      q.pop();
      sum+=t.fish;
      t.fish>=t.d?t.fish-=t.d:t.fish=0;
      f[t.ID]+=5;            //当前位置加上时间
      q.push(t);
    }
    if(sum>maxsum)           //更新最优解
    {
      maxsum=sum;
      for(int j=0; j<n; j++)
        ans[j]=f[j];
    }
  }
}

int main()
{
  freopen("fish.in","r",stdin);
  freopen("fish.out","w",stdout);
  while(scanf("%d",&n) && n)
  {
    scanf("%d",&h);
    for(int i=0; i<n; i++)
    {
      scanf("%d",&fish[i].fish);
      fish[i].ID=i;
    }
    for(int i=0; i<n; i++)
      scanf("%d",&fish[i].d);
    fish[0].time=0;
    for(int i=1,t; i<n; i++)
    {
      scanf("%d",&t);
      fish[i].time=fish[i-1].time+t*5;
    }
    GetFish(h*60);
    for(int i=0; i<n; i++)
      printf("%d%s",ans[i],i==n-1?"\n":", ");
    printf("Number of fish expected: %d\n\n",maxsum);
  }
  return 0;
}
