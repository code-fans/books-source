//ǰ���ǵ������������
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int Cnt;

struct node
{
  int to;
  int next;
} edge[maxn];
int Head[maxn];
bool vis[maxn];

void AddEdge(int u,int v)
{
  edge[++Cnt].to=v;
  edge[Cnt].next=Head[u];
  Head[u]=Cnt;
}

void Dfs(int x)
{
  vis[x]=1;                                 //���x��㱻����
  cout<<x<<"\n";
  for(int k=Head[x]; k!=-1; k=edge[k].next)
    if(!vis[edge[k].to])                    //���û�б����ʹ�
      Dfs(edge[k].to);                      //�����������
}

int main()
{
  freopen("dfs.in","r",stdin);
  freopen("dfs.out","w",stdout);
  int n,m,u,v;
  cin>>n>>m;
  memset(Head,-1,sizeof(Head));
  for(int i=1; i<=m; i++)
  {
    cin>>u>>v;
    AddEdge(u,v);                           //����ͼ������α�
    AddEdge(v,u);
  }
  Dfs(1);                                   //�ӽ��1��ʼ����
  return 0;
}

