//唯一最短路 —次小生成树1
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10001;

int n,m,del;                           //del为删除的边的下标
int dad[110];                          //并查集数组,请参见并查集一章
bool flag[MAXN];                       //标记某条边是否在最小生成树中
struct data
{
  int x,y,w;
} edge[MAXN];                          //记录边的起点和终点，还有权值

int Cmp(data a,data b)
{
  return a.w<b.w;
}

int FindFather(int x)                  //寻找根结点并路径压缩
{
  return dad[x]==x?x:dad[x]=FindFather(dad[x]);
}

int Kruskal()
{
  int ans=0,count=0,index=0;
  for(int i=1; i<=n; i++)
    dad[i]=i;                         //并查集初始化
  while(count<n-1)                    //还没有完成最小树时
  {
    index++;                          //index从1开始
    if(index!=del)                    //初次kruskal时，del=0,所以不会触发判断
    {
      int x=FindFather(edge[index].x);//寻找根结点
      int y=FindFather(edge[index].y);
      if(x!=y)
      {
        count++;
        ans+=edge[index].w;
        dad[x]=dad[y];                //合并集合
        if(del==0)                    //第一次生成最小树时
          flag[index]=1;              //标记该边在最小生成树中
      }
    }
  }
  return ans;
}

int main()
{
  freopen("OnePath.in","r",stdin);
  freopen("OnePath.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++)
    scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
  sort(edge+1,edge+1+m,Cmp);          //贪心，排序，按权值
  memset(flag,0,sizeof(flag));        //初始化为未被使用过
  int ans=Kruskal();
  if(m==n-1)                          //唯一最小生成树，直接输出结果
  {
    printf("%d\n",ans);
    return 0;
  }
  for(int t=1; t<=n-1; t++)           //进行n-1次删边的操作
    for(int i=++del; i<=m; i++)       //寻找下一个删除的边
      if(flag[i])                     //如果该边在最小生成树中
      {
        del=i;                        //确定下一个要删除的边
        if(Kruskal()==ans)            //生成次小生小树，且和最小生成树等值
        {
          printf("Not Unique!\n");
          exit(0);
        }
      }
  printf("%d\n",ans);
  return 0;
}

