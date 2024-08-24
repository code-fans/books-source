//kruskal算法
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000

int n,e;                          //点数和边数
int x[MAXN],y[MAXN],w[MAXN];      //x为边的起点，y为终点，w为边的权值
int dad[MAXN];                    //每个结点属于的父亲集合

void Sort(int i,int j)            //快排，给边权排序
{
  if(i>=j)
    return ;
  int m=i,n=j;
  int k=w[(i+j)>>1];           //取中值
  while(m<=n)
  {
    while(w[m]<k)
      m++;
    while(w[n]>k)
      n--;
    if(m<=n)
    {
      swap(x[m],x[n]);
      swap(y[m],y[n]);
      swap(w[m],w[n]);
      m++;
      n--;
    }
  }
  Sort(i,n);
  Sort(m,j);
}

int Getfather(int x)                //查找点x属于的集合
{
  return dad[x]==x?x:dad[x]=Getfather(dad[x]);
}

void Kruskal()
{
  for(int i=1; i<=n; i++)
    dad[i]=i;                      //初始化点的集合
  int p=1,ans=0;//p为顶点数，为加快速度p，初始化为1，所以当p=n时结束计算
  for(int i=1; i<=e; i++)
    if(getfather(x[i])!=getfather(y[i]))  //如边的两点不在同一集合，则归并
    {
      ans+=w[i];                                  //加入这条边并统计其权值
      dad[getfather(x[i])]=y[i];     //合并为同一父亲集合,此处是取y[i]的值
      p++;
      if(p == n)               //如果最小生成树中的顶点数等于全部顶点数 - 1
      {
        cout<<ans<<"\n";
        return ;
      }
    }
}

int main()
{
  freopen("Line.in","r",stdin);
  freopen("Line.out","w",stdout);
  cin>>n>>e;                          //输入结点数和边数
  for(int i=1; i<=e; i++)
    cin>>x[i]>>y[i]>>w[i];
  Sort(1,e);                          //将边按权值大小排序
  Kruskal();
  return 0;
}

