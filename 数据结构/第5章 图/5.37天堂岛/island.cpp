//���õ�
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;

struct node
{
  int to,next;
} edge[MAXN*5];
int Time,cnt,top;
int head[MAXN],dfn[MAXN],low[MAXN],Stack[MAXN],degree[MAXN];
bool vis[MAXN];

void AddEdge(int u,int v)
{
  edge[cnt].to=v;
  edge[cnt].next=head[u];
  head[u]=cnt;
  cnt++;
}

void Dfs(int u,int fa)
{
  dfn[u]=low[u]=++Time;
  vis[u]=true;
  Stack[top++]=u;                 //�����ջ
  for(int i=head[u]; i!=-1; i=edge[i].next)
  {
    int v=edge[i].to;
    if(v!=fa)
      if(!vis[v])
      {
        Dfs(v,u);
        low[u]=min(low[u],low[v]);
      }
      else
        low[u]=min(low[u],dfn[v]);
  }
  if(dfn[u]==low[u])              //������u��ǿ��ͨ�����ĸ�
    while(Stack[top]!=u && top>0)
    {
      low[Stack[top-1]]=low[u];   //��Ϊ֮ǰtop++������top������ָ��һ��λ��
      top--;                      //��ջ����֪�Ƿ�˫��ͨ�����ж��Գ�ջΪ��׼
      vis[Stack[top]]=false;
    }
}

int main()
{
  freopen("island.in","r",stdin);
  freopen("island.out","w",stdout);
  int u,v,n,m;
  scanf("%d%d",&n,&m);
  memset(head,-1,sizeof(head));
  for(int i=0; i<m; i++)
  {
    scanf("%d%d",&u,&v);
    u--;
    v--;
    AddEdge(u,v);                 //����ͼ��˫���
    AddEdge(v,u);
  }
  Dfs(0,-1);
  for(int i=0; i<n; i++)
    for(int j=head[i]; j!=-1; j=edge[j].next)
      if(low[i]!=low[edge[j].to])
        degree[low[edge[j].to]]++;
  cnt=0;
  for(int i=0; i<=n; i++)
    if(degree[i]==1)
      cnt++;
  printf("%d\n",(cnt+1)/2);
  return 0;
}

