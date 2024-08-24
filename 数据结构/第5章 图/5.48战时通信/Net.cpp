//սʱͨ��
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
int pre[MAX],ID[MAX],vis[MAX];               //pre[]��ʾ������
double In[MAX];                              //�ñ�Ȩֵ

double Dis(point a,point b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Zhu_Liu(int root,int N,int M)
{
  double Ans = 0;
  while(true)
  {
    //1. ����̻�����A
    for(int i=0; i<N; i++)
      In[i] = INF;
    for(int i=0; i<M; i++)
    {
      int u = E[i].u;
      int v = E[i].v;
      if(E[i].Val < In[v] && u != v)          //��������Ի��ߣ�����С���
      {
        pre[v] = u;
        In[v] = E[i].Val;
      }
    }
    for(int i=0; i<N; i++)
      if(i!=root && In[i] == INF) return -1;  //�е�û�����,����С����ͼ

    //2.�һ�
    int Ring = 0;
    memset(ID,-1,sizeof(ID));
    memset(vis,-1,sizeof(vis));
    In[root] = 0;
    for(int i=0; i<N; i++)                    //���ÿ����
    {
      Ans += In[i];
      int v = i;
      while(vis[v]!=i && ID[v]==-1 && v!=root)//���vδ����δ��ǲ��Ǹ�
      {
        vis[v] = i;//��Ǳ�֤��������ѭ��,�����ѭ����vis[v]=i��ʾ�γɻ�
        v = pre[v];                           //�ҵ�ǰ���
      }
      if(v != root && ID[v] == -1)        //��Ȼֻ�е�vis[v]=iʱ��һ����
      {
        for(int u=pre[v]; u!=v; u=pre[u])     //�����
          ID[u] = Ring;
        ID[v]=Ring++;
      }
    }

    if(Ring == 0)    break;                   //�޻�
    for(int i=0; i<N; i++)
      if(ID[i] == -1)
        ID[i] = Ring++;

    //3.����,������ͼ
    for(int i=0; i<M; i++)
    {
      int v = E[i].v;
      int u = E[i].u;
      E[i].u = ID[u];
      E[i].v = ID[v];
      if(u!= v)
        E[i].Val -= In[v];
    }
    N = Ring;                                 //���½����
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
      E[i].u--;                               //�±��0��ʼ
      E[i].v--;
      E[i].Val=E[i].u!=E[i].v?Dis(p[E[i].u],p[E[i].v]):INF;
    }
    double ans=Zhu_Liu(0,n,m);
    ans==-1?printf("poor snoopy\n"):printf("%.2f\n",ans);
  }
  return 0;
}

