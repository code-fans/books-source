//拓扑排序
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

int n,m;                                 //n为结点数,m为边数
int mark[MAXN],ind[MAXN],Stack[MAXN];
//mark为结点的拓扑序,ind为结点的入度数,stack为一个栈
bool w[MAXN][MAXN];                     //邻接表

void TopoSort()
{
  int u,t;
  int top = -1;                         //栈顶指针
  //将入度为0的结点入栈并且做出标记
  for(int i = 1 ; i <= n ; i ++)
    if(ind[i] == 0 )
    {
      mark[i] = 1;
      Stack[++top] = i;
      ind[i] = -1;
    }

  do                                    //用DFS的方式标记结点的拓扑序
  {
    u = Stack[top--];//取出栈中的一个结点并将该与该结点相邻的结点的入度减1
    for(int i=1; i<=n; i++)
      if(w[u][i] && ind[i] != -1)
        ind[i]--;

    for(int i=1; i<=n; i++)//查找当前是否有入度为0且没有入栈的结点并将其入栈
      if(ind[i] == 0)
      {
        mark[i] = mark[u] + 1;
        Stack[++top] = i;
        ind[i] = -1;
      }
  }
  while(top >= 0);
}

int main()
{
  cin>>n>>m;                           //结点数和边数n,m
  int u,v;
  for(int i=1; i<=m; i++)
  {
    cin>>u>>v;
    w[u][v] = true;
    ind[v]++;
  }
  TopoSort();
  for(int i=1; i<=n; i++)
    cout<<mark[i]<<" ";
  cout<<"\n";
  return 0;
}

