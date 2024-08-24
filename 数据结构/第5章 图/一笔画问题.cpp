//一笔画问题
//此程序样例与例图无关
#include <bits/stdc++.h>
using namespace std;

int graph[7][7]= {0,0,0,0,0,0,0,
                  0,0,1,0,0,1,1,
                  0,1,0,1,1,0,1,
                  0,0,1,0,1,0,0,
                  0,0,1,1,0,1,1,
                  0,1,0,0,1,0,1,
                  0,1,1,0,1,1,0
                 };

int a[7],total,edge;            //a[]保存每个顶点的度

int Draw(int v)
{
  int k=0;
  if(total==edge) return 1;
  for(int i=1; i<7; i++)
  {
    if(graph[v][i]==1)
    {
      k=1;
      graph[v][i]=0;
      graph[i][v]=0;
      edge+=2;
      if(Draw(i))               //递归，如果可以继续画下去
      {
        printf("%3d",i);
        return 1;
      }
      else
      {
        graph[v][i]=1;          //恢复
        graph[i][v]=1;
        edge-=2;
        k=0;
      }
    }
  }
  if(k==0) return 0;
}

int main()
{
  int v,k=0;
  for(int i=1; i<7; i++)
  {
    for(int j=1; j<7; j++)
      if(graph[i][j]==1)
        a[i]++;                 //统计每个顶点的度
    total+=a[i];
    if(a[i]%2==1)               //统计奇点个数
    {
      k++;
      v=i;
    }
  }
  if(k>2)
    printf("No solution\n");
  else
  {
    Draw(v);                    //从任一个奇点v出发
    printf("%3d",v);
  }
  return 0;
}

