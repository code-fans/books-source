//车站分级
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int n,m,Ans=1,station[MAX],Line[MAX][MAX],ind[MAX],dist[MAX];
bool Stop[MAX];

void TopoSort()                        //拓扑排序
{
  queue <int> q;
  for(int i=1; i<=n; i++)
    if(ind[i]==0)
    {
      q.push(i);
      dist[i]=1;
    }
  while(!q.empty())
  {
    int i=q.front();
    q.pop();                           //去除队首元素 i
    for(int j=1; j<=n; j++)
      if(Line[i][j])                   //如果 i->j 有边
      {
        ind[j]--;                      // j 的入度减1,加不加判断为负数无所谓
        if(ind[j]==0)                  //若j变成入读为 0的点，则进队列
        {
          q.push(j);
          dist[j]=dist[i]+1;           //其级在i的基础上加 1（i的等级小于j）
          Ans=max(Ans,dist[j]);
        }
      }
  }
}

int main()
{
  //freopen("level.in","r",stdin);
  //freopen("level.out","w",stdout);
  scanf("%d %d",&n,&m);
  for(int i=1,s; i<=m; i++)
  {
    memset(Stop,0,sizeof(Stop));       //表示是否是停靠站
    scanf("%d",&s);
    for(int j=1; j<=s; j++)
    {
      scanf("%d",&station[j]);
      Stop[station[j]]=true;
    }
    for(int j=station[1]; j<=station[s]; j++)//枚举站点
      if(!Stop[j])			                 //若不是已停靠的就小于所有停靠站的等级
        for(int k=1; k<=s; k++)	             //枚举已停靠站点
          if(!Line[j][station[k]])
          {
            Line[j][station[k]]=1;           //Line[i][j]表示j>i的级别
            ind[station[k]]++;
          }
  }
  TopoSort();
  cout<<Ans<<endl;
  return 0;
}
