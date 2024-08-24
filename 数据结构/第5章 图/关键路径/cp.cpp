//关键路径
#include <bits/stdc++.h>
using namespace std;
const int Ns=1e5;
const int Ms=1e7;

//邻接链表
int p[Ns],cnt;
int u,v,w;
struct edge
{
  int v,w,next;
} e[Ms];

void AddEdge(int u,int v,int w)
{
  e[++cnt]=(edge)
  {
    v,w,p[u]
  };
  p[u]=cnt;
}

struct queue                                //手写双端队列
{
  int head,tail,a[Ns];
  queue()
  {
    tail=1;
  }
  void push(int k)
  {
    a[++tail]=k;
  }
  void pop()
  {
    ++head;
  }
  void pop_back()
  {
    --tail;
  }
  int front()
  {
    return a[head];
  }
  int back()
  {
    return a[tail];
  }
  bool empty()
  {
    return head>tail;
  }
} q;

//im[i]表示入度，ve[i]表示最早,vl[i]表示最迟的开始时间
int N,M,im[Ns],ve[Ns],vl[Ns];

void Init()
{
  scanf("%d%d",&N,&M);                      //输入事件数，活动数
  for (int i=0; i<M; ++i)
  {
    scanf("%d%d%d",&u,&v,&w);               //从u到v顶点的权值为w
    AddEdge(u,v,w);
    ++im[v];
  }
}

void Work()
{
  //拓扑排序正向更新 ve
  for (int i=1; i<=N; ++i)
    if (!im[i])
      q.push(i);
  while(!q.empty())
  {
    u=q.front();
    q.pop();
    for (int i=p[u]; i; i=e[i].next)
    {
      ve[e[i].v]=max(ve[e[i].v],ve[u]+e[i].w);
      if (!(--im[e[i].v]))
        q.push(e[i].v);
    }
  }
  //反向更新 vl
  q.head=1;
  while(!q.empty())
  {
    u=q.back();
    q.pop_back();
    for (int i=p[u]; i; i=e[i].next)
    {
      if (!vl[e[i].v])
        vl[e[i].v]=ve[e[i].v];
      if (!vl[u])
        vl[u]=vl[e[i].v]-e[i].w;
      else
        vl[u]=min(vl[u],vl[e[i].v]-e[i].w);
    }
  }
}

int main()
{
  freopen("cp.in","r",stdin);
  freopen("cp.out","w",stdout);
  Init();
  Work();
  for (int i=1; i<=N; ++i)                  //输出
    printf("POINT[%d],ve[%d]=%d ,vl[%d]=%d\n",i,i,ve[i],i,vl[i]);
  return 0;
}

