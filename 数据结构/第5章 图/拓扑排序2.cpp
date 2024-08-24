//拓扑排序算法2
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;

int List[MAX],visit[MAX],k;                //List保存拓扑序
struct
{
  int n;                                   //保存相连的顶点数
  int adjvex[MAX];                         //保存相连的顶点
} Edge[MAX];

void DFS(int cur)
{
  int next;
  visit[cur]=-1;
  for(int i=0; i<Edge[cur].n; i++)         //遍历所有的连接边
  {
    next = Edge[cur].adjvex[i];            //找到下一个连接边
    if(visit[next]==0)                     //如果没有访问过，则DFS
      DFS(next);
    else if(visit[next]==-1)               //有回边出现意味着有回路
    {
      cout<<"-1"<<endl;
      exit(0);
    }
  }
  visit[cur] = 1;
  List[--k] = cur;                         //按结点完成的顺序入列，逆序保存
}

int main()
{
  int n,e,a,b;
  cin>>n>>e;                               //输入顶点数n和边数e
  for(int i=1; i<=n; i++)
    Edge[i].n=0;
  for(int i=0; i<e; i++)                   //输入边
  {
    cin>>a>>b;
    Edge[a].adjvex[Edge[a].n++]=b;
  }
  k=n;                                     //k为List的下标
  DFS(1);
  for(int i=0; i<n; i++)
    cout<<List[i]<<" ";
  return 0;
}

