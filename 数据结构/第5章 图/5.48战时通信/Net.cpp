//战时通信
#include <bits/stdc++.h>
using namespace std;
#define MAX 110
const double INF=0x3f3f3f3f;

struct point
{
  double x,y;
} p[MAX];

struct Node
{
  int u,v;
  double Val;
} E[MAX*MAX+5];

int n,m;
int pre[MAX],ID[MAX],vis[MAX];               //pre[]表示入边起点
double In[MAX];                              //该边权值

double Dis(point a,point b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Zhu_Liu(int root,int N,int M)
{
  double Ans = 0;
  while(true)
  {
    //1. 找最短弧集合A
    for(int i=0; i<N; i++)
      In[i] = INF;
    for(int i=0; i<M; i++)
    {
      int u = E[i].u;
      int v = E[i].v;
      if(E[i].Val < In[v] && u != v)          //如果不是自环边，找最小入边
      {
        pre[v] = u;
        In[v] = E[i].Val;
      }
    }
    for(int i=0; i<N; i++)
      if(i!=root && In[i] == INF) return -1;  //有点没有入边,无最小树形图

    //2.找环
    int Ring = 0;
    memset(ID,-1,sizeof(ID));
    memset(vis,-1,sizeof(vis));
    In[root] = 0;
    for(int i=0; i<N; i++)                    //标记每个环
    {
      Ans += In[i];
      int v = i;
      while(vis[v]!=i && ID[v]==-1 && v!=root)//如果v未访问未标记不是根
      {
        vis[v] = i;//标记保证不会无限循环,且如果循环到vis[v]=i表示形成环
        v = pre[v];                           //找到前结点
      }
      if(v != root && ID[v] == -1)        //显然只有当vis[v]=i时是一个环
      {
        for(int u=pre[v]; u!=v; u=pre[u])     //环编号
          ID[u] = Ring;
        ID[v]=Ring++;
      }
    }

    if(Ring == 0)    break;                   //无环
    for(int i=0; i<N; i++)
      if(ID[i] == -1)
        ID[i] = Ring++;

    //3.缩点,建立新图
    for(int i=0; i<M; i++)
    {
      int v = E[i].v;
      int u = E[i].u;
      E[i].u = ID[u];
      E[i].v = ID[v];
      if(u!= v)
        E[i].Val -= In[v];
    }
    N = Ring;                                 //更新结点数
    root = ID[root];
  }
  return Ans;
}


int main()
{
  //freopen("Net.in","r",stdin);
  //freopen("Net.out","w",stdout);
  while(~scanf("%d%d",&n,&m))
  {
    for(int i=0; i<n; i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i=0; i<m; i++)
    {
      scanf("%d%d",&E[i].u,&E[i].v);
      E[i].u--;                               //下标从0开始
      E[i].v--;
      E[i].Val=E[i].u!=E[i].v?Dis(p[E[i].u],p[E[i].v]):INF;
    }
    double ans=Zhu_Liu(0,n,m);
    ans==-1?printf("poor snoopy\n"):printf("%.2f\n",ans);
  }
  return 0;
}

