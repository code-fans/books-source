//拓扑排序 - 队列实现（也可以数组模拟堆栈实现）
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001;

bool w[MAXN][MAXN];        //w[]保存边是否存在
int ind[MAXN],n,m,a,b;     //ind[]保存结点入度
queue<int>q;               //队列保存拓扑排序后路径

void TopoSort()
{
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)//找到编号最小的、入度为0的结点
      if(ind[j]==0)
      {
        q.push(j);         //该结点入队
        ind[j]=-1;
        for(int k=1; k<=n; ++k)
          if(w[j][k])      //处理和该结点相关的结点
          {
            ind[k]--;      //相关结点的入度减 1
            w[j][k]=0;     //删边
          }
        break;
      }
}

int main()
{
  freopen("ranking.in","r",stdin);
  freopen("ranking.out","w",stdout);
  cin>>n>>m;             //输入结点数和边数
  for(int i=0; i<m; i++)
  {
    cin>>a>>b;
    if(w[a][b]==0)       //避免重复的数据输入
    {
      w[a][b]=true;      //标记连边
      ind[b]++;          //入度加一
    }
  }
  TopoSort();            //拓扑排序
  while(!q.empty())      //输出拓扑序
  {
    printf("%d%c",q.front(),q.size()==1?'\n':' ');
    q.pop();
  }
  return 0;
}

