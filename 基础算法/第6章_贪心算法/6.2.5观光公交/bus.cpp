//观光公交
#include<bits/stdc++.h>
using namespace std;
#define N 30001

int n,m,k;
int Time[N],last[N],sum[N],effect[N],fast[N];
int ans;

struct node
{
  int time,sta,end;       //出发时间，起点、终点编号
} man[N];

int Calc(int k)
{
  effect[n]=effect[n-1]=n;//effect[i]为i站点所能影响到的最远站点
  while(k--)              //直到加速器用完
  {
    for(int i=n-2; i>=1; --i)//倒推
      fast[i+1]<=last[i+1]?effect[i]=i+1:effect[i]=effect[i+1];//到下一站等或不等
    int obj,MAX=-1;
    for(int i=1; i<n; ++i)
    {
      int total=sum[effect[i]]-sum[i];//找到最多影响的人数
      if(total>MAX && Time[i]>0)//时间不能减为0
      {
        MAX=total;
        obj=i;//标记最优情况减的点
      }
    }
    ans-=MAX;//更新ans
    Time[obj]--;//使用加速器，所以时间减一
    for(int i=2; i<=n; ++i)//更新fast[]
      fast[i]=max(fast[i-1],last[i-1])+Time[i-1];
  }
  return ans;
}

int main()
{
//  //freopen("bus.in","r",stdin);
//  //freopen("bus.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k); //景点数、乘客数和氮气加速器个数
  for(int i=1; i<n; ++i)
    scanf("%d",&Time[i]);   //从第i个景点开往第i＋1个景点所需要的时间
  for(int i=1; i<=m; ++i)
  {
    scanf("%d%d%d",&man[i].time,&man[i].sta,&man[i].end);//第i位乘客来到出发景点的时刻，出发的景点编号和到达的景点编号
    last[man[i].sta]=max(last[man[i].sta],man[i].time);//更新最后到a[i].start的时间
    sum[man[i].end]++;//统计到man[i].end站的总人数
  }
  fast[1]=last[1];
  for(int i=2; i<=n; ++i)
  {
    sum[i]+=sum[i-1];//到i站点的总人数的前缀和处理
    fast[i]=max(fast[i-1],last[i-1])+Time[i-1];//统计i车站最快发车时间
  }
  for(int i=1; i<=m; ++i)//计算出无加速器的解
    ans+=fast[man[i].end]-man[i].time;
  printf("%d\n",Calc(k));
  return 0;
}

