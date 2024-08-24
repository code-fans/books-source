//Dijkstra堆优化
#include <bits/stdc++.h>
using namespace std;
#define Max 0xfffffff

int n,ms;
int Map[1501][1501];                 //存储图
int visit[1501];                     //设置访问标记
int heap[1501];                      //堆
int pos[1501];                       //pos[i]存储堆中第i点在图中的位置
int posh[1501];                      //posh[i]存储图中的点i在堆中的位置

void Minheap(int x)                    //维护最小堆
{
  int t=x;
  int l=t<<1;                          //左子结点
  int r=(t<<1)+1;                      //右子结点
  if(l<=ms && heap[l]<heap[t])
    t=l;
  if(r<=ms && heap[r]<heap[t])
    t=r;
  if(t!=x)
  {
    swap(heap[x],heap[t]);
    swap(posh[pos[x]],posh[pos[t]]);
    swap(pos[x],pos[t]);
    Minheap(t);                        //递归继续向下调整堆
  }
}

void Insert(int x)                     //改变堆中某个元素的值
{
  while(x>1 && heap[x]<heap[x>>1])
  {
    swap(heap[x],heap[x>>1]);
    swap(posh[pos[x]],posh[pos[x>>1]]);
    swap(pos[x],pos[x>>1]);
    x>>=1;
  }
}

void Dijkstra(int x)                   //求从x点到其它的单源最短路径
{
  int Min,p,q;
  for(int i=1; i<=n; i++)              //初始化堆中元素
    heap[i]=Map[1][i];
  heap[x]=0;
  for(int i=1; i<=n; i++)              //初始化
    pos[i]=posh[i]=i;
  for(int i=n>>1; i>=1; i--)           //建最小堆
    Minheap(i);
  for(int i=1; i<n; i++)
  {
    p=pos[1];                          //将最小的元素提出来，并标记该点
    q=heap[1];                         //q为当前最短结点
    visit[p]=1;
    swap(heap[1],heap[ms]);
    swap(posh[pos[1]],posh[pos[ms]]);
    swap(pos[1],pos[ms]);        //将最大的元素和最小的元素交换，这样才能维护堆
    ms--;                        //每确定一个点，堆都会缩小1
    Minheap(1);                  //维护最小堆
    for(int j=1; j<=n; j++)      //更新未查找顶点的最小距离总和
      if(!visit[j] && q+Map[p][j]<heap[posh[j]])
      {
        heap[posh[j]]=q+Map[p][j];
        Insert(posh[j]);         //修改j点在堆里的位置
      }
  }
  for(int i=1; i<=n; i++)        //打印最短路径
    cout<<heap[posh[i]]<<'\n';
}

void Init()
{
  cin>>n;                        //n个结点
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
      cin>>Map[i][j];
      if(Map[i][j]==-1)           //若不存在路径,则为+∞
        Map[i][j]=Max;
    }
  ms=n;                          //堆元素为n
}

int main()
{
  //freopen("map.in","r",stdin);
  //freopen("map.out","w",stdout);
  Init();                        //读入图
  Dijkstra(1);
  return 0;
}

