//Prim算法的演示程序 -无向图
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2001
#define INF 0x7f

int w[MAXN][MAXN];                  //两点之间边的权值
int mincount[MAXN];                 //从集合顶点到该顶点的最小权值
int n,e,x,y,W;

void Prim(int star)
{
  int count=0,k;                    //count为生成树所有边的权值和
  for(int i=1; i<=n; i++)           //计算每个点到star点的最小权值
    mincount[i]=w[star][i];         //如果没有连边就是无穷大
  mincount[star]=0;                 //此处设加入集合的mincount为0

  for(int i=1; i<n; i++)
  {
    int Min=INF;
    for(int j=1; j<=n; j++)         //找到集合外最小权值的边
      if(mincount[j]!=0 && mincount[j]<Min)//集合外的mincount不等于0
      {
        Min=mincount[j];
        k=j;                        //最小的边的顶点存入k
      }
    mincount[k]=0;                  //把这个点加入到最小生成树中
    count+=Min;                     //将这条边权值加入到最小生成树中

    for(int j=1; j<=n; j++)         //修正集合外点到k点的最小权值
      mincount[j]=min(mincount[j],w[k][j]);
  }
  cout<<count<<"\n";
}

int main()
{
  freopen("Line.in","r",stdin);
  freopen("Line.out","w",stdout);
  memset(w,127,sizeof(w));         //设所有边的边权为无穷大
  cin>>n>>e;
  for(int i=1; i<=e; i++)
  {
    cin>>x>>y>>W;
    w[x][y]=W;
    w[y][x]=W;
  }
  Prim(1);                         //从标号为1的顶点开始构造生成树
  return 0;
}

