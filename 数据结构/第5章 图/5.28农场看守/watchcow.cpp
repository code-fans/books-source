//农场看守
//存图时把每条无向边看成两条相反的有向边
#include <bits/stdc++.h>
using namespace std;

int V,E;
int head[10010],visit[10010];
queue<int> ans;

struct EdgeNode
{
  int to,next;
} Edge[20010];

void DFS(int now)
{
  stack<int> Stack;
  Stack.push(now);
  for(int i = head[now]; i!=-1; i=Edge[i].next)
    if(!visit[i])
    {
      visit[i] = 1;
      DFS( Edge[i].to );
    }
  ans.push(Stack.top());
  Stack.pop();
}

int main()
{
  freopen("watchcow.in", "r", stdin);
  freopen("watchcow.out", "w", stdout);
  scanf("%d%d", &V, &E);
  memset(head, -1, sizeof(head));
  for(int i=1,u,v; i<=E; i++)
  {
    scanf("%d%d", &u, &v);
    Edge[2*i-1].to=v;
    Edge[2*i-1].next=head[u];
    head[u]=2*i-1;
    Edge[2*i].to=u;
    Edge[2*i].next=head[v];
    head[v]=2*i;
  }
  DFS(1);
  while(!ans.empty())
  {
    printf("%d\n",ans.front());
    ans.pop();
  }
  return 0;
}
