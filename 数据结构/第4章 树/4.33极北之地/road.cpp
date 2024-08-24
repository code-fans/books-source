//����֮�� - DP
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;

struct edge
{
  int v,len,next;
} edge[MAXN<<2];
int ans,k;
int head[MAXN],first[MAXN],second[MAXN];          //ǰ���ǣ��·���γ�·

void AddEdge(int u,int v,int len)                 //ǰ���Ǳ�ʾ���μ�������
{
  edge[++k].v=v;
  edge[k].len=len;
  edge[k].next=head[u];
  head[u]=k;
}

void Dp(int u,int father)                               //���ζ���
{
  for(int i=head[u]; i; i=edge[i].next)
  {
    int v=edge[i].v;
    if(v!=father)
    {
      Dp(v,u);
      if(first[v]+edge[i].len>first[u])                 //�ܸ������ֵ
      {
        second[u]=first[u];                         //�δ�ֵ��Ϊԭ�����ֵ
        first[u]=first[v]+edge[i].len;
      }
      else                                          //�����ܲ��ܸ��´δ�ֵ
        second[u]=max(second[u],first[v]+edge[i].len);
    }
  }
  ans=max(ans,first[u]+second[u]);
}

int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);

  int u,v,len;
  while(~scanf("%d%d%d",&u,&v,&len))
  {
    AddEdge(u,v,len);
    AddEdge(v,u,len);
  }
  Dp(1,0);
  cout<<ans<<endl;
  return 0;
}

