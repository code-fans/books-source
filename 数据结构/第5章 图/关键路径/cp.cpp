//�ؼ�·��
#include <bits/stdc++.h>
using namespace std;
const int Ns=1e5;
const int Ms=1e7;

//�ڽ�����
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

struct queue                                //��д˫�˶���
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

//im[i]��ʾ��ȣ�ve[i]��ʾ����,vl[i]��ʾ��ٵĿ�ʼʱ��
int N,M,im[Ns],ve[Ns],vl[Ns];

void Init()
{
  scanf("%d%d",&N,&M);                      //�����¼��������
  for (int i=0; i<M; ++i)
  {
    scanf("%d%d%d",&u,&v,&w);               //��u��v�����ȨֵΪw
    AddEdge(u,v,w);
    ++im[v];
  }
}

void Work()
{
  //��������������� ve
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
  //������� vl
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
  for (int i=1; i<=N; ++i)                  //���
    printf("POINT[%d],ve[%d]=%d ,vl[%d]=%d\n",i,i,ve[i],i,vl[i]);
  return 0;
}

