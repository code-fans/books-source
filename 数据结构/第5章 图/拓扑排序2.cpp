//���������㷨2
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;

int List[MAX],visit[MAX],k;                //List����������
struct
{
  int n;                                   //���������Ķ�����
  int adjvex[MAX];                         //���������Ķ���
} Edge[MAX];

void DFS(int cur)
{
  int next;
  visit[cur]=-1;
  for(int i=0; i<Edge[cur].n; i++)         //�������е����ӱ�
  {
    next = Edge[cur].adjvex[i];            //�ҵ���һ�����ӱ�
    if(visit[next]==0)                     //���û�з��ʹ�����DFS
      DFS(next);
    else if(visit[next]==-1)               //�лر߳�����ζ���л�·
    {
      cout<<"-1"<<endl;
      exit(0);
    }
  }
  visit[cur] = 1;
  List[--k] = cur;                         //�������ɵ�˳�����У����򱣴�
}

int main()
{
  int n,e,a,b;
  cin>>n>>e;                               //���붥����n�ͱ���e
  for(int i=1; i<=n; i++)
    Edge[i].n=0;
  for(int i=0; i<e; i++)                   //�����
  {
    cin>>a>>b;
    Edge[a].adjvex[Edge[a].n++]=b;
  }
  k=n;                                     //kΪList���±�
  DFS(1);
  for(int i=0; i<n; i++)
    cout<<List[i]<<" ";
  return 0;
}

