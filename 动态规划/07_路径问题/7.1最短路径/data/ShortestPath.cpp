//最短路径
#include <bits/stdc++.h>
using namespace std;
#define IMAX 0x7fffffff

vector <int> vec;                                //用于存放拓扑排序的值
int n,o=-1,t=-1,th=-1;
int a[101][101];

void TopSort(int a[101][101],int *indegree)      //拓扑排序
{
  queue <int> q;
  while(!q.empty() || vec.size()<n)
  {
    for(int i=1; i<=n; i++)
      if(indegree[i]==0)
      {
        q.push(i);                               //将入度为0的点入队
        indegree[i]=-1;                          //标记为不可再访问
      }
    int v=q.front();
    vec.push_back(v);                            //取队首元素入拓扑排序数组
    q.pop();                                     //队首元素出队
    for(int i=1; i<=n; i++)                      //删除队首指向其它点的边
      if(a[v][i]!=-1 && indegree[i]!=-1)
        indegree[i]--;
  }
}

int main()
{
  //freopen("ShortestPath.in","r",stdin);
  //freopen("ShortestPath.out","w",stdout);
  scanf("%d",&n);
  int f[n+1];
  int indegree[n+1];                              //保存每个点的入度
  memset(f,127,sizeof(f));
  memset(indegree,0,sizeof(indegree));            //每个点的入度初始为0
  memset(a,-1,sizeof(a));
  while(o!=0 && t!=0 && th!=0)
  {
    cin>>o>>t>>th;
    a[o][t]=th;
    indegree[t]++;                                //顶点t入度加1
  }
  TopSort(a,indegree);                            //拓扑排序
  f[n]=0;
  for(int i=n-2; i>=0; i--)
    for(int j=n-1; j>i; j--)
    {
      int I=vec[i],J=vec[j];
      if(a[I][J]>0 && f[J]!=0x7f7f7f7f)
        f[I]=min(f[I],f[J]+a[I][J]);
    }
  printf("%d\n",f[1]);
  return 0;
}

