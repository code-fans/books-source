//广度优先搜索
#include <bits/stdc++.h>
using namespace std;
int Head[1000];
int vis[1000];
int N, M,Cnt;

struct EdgeNode
{
  int to;
  int next;
} edge[1000];

void BFS()
{
  queue<int> Queue;
  for(int i = 1; i <= N; i++)                       //从结点1开始
    if(!vis[i])
    {
      vis[i] = 1;                                   //标记该点已访问
      Queue.push( i );
      while( !Queue.empty() )                       //当队列不为空
      {
        int k = Queue.front();                      //获取队首元素
        cout<<k<<" ";                               //输出队首元素
        Queue.pop();                                //队首元素出队
        for(int j=Head[k]; j!=-1; j=edge[j].next)
          if(!vis[edge[j].to])
          {
            vis[edge[j].to] = 1;
            Queue.push(edge[j].to);
          }
      }
    }
}

void AddEdge(int u,int v)
{
  edge[++Cnt].to=v;
  edge[Cnt].next=Head[u];
  Head[u]=Cnt;
}

int main()
{
  memset(Head, -1, sizeof(Head));
  cin >> N >> M;
  for(int i = 1; i <= M; i++)
  {
    int x, y;
    cin >> x >> y;
    AddEdge(x,y);
    AddEdge(y,x);
  }
  BFS();
  return 0;
}

