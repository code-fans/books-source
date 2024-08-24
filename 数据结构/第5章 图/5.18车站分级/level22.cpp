//车站分级
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int Stack[MAX<<6],top,node[MAX],deep[MAX],In[MAX],OUT[MAX];
bool Map[MAX][MAX];
int m,n,N;

int main()
{
  //freopen("level.in","r",stdin);
  //freopen("level.out","w",stdout);
  int x,y,ans=0,Count1,Count2,x1;
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++) //输入的建图很麻烦，时间复杂度有n3次方，但是通过小小优化，对于测试数据是可以过的，但是最坏情况仍然是n3次方。
  {
    Count1=Count2=0;
    scanf("%d%d",&N,&x);
    In[++Count1]=x;
    for(int j=2; j<=N; j++)
    {
      scanf("%d",&x1);
      for(int k=x+1; k<x1; k++)
        OUT[++Count2]=k;
      In[++Count1]=x1;
      x=x1;
    }
    for(int j=1; j<=Count1; j++)
      for(int k=1; k<=Count2; k++)
        if(!Map[OUT[k]][In[j]])
        {
          Map[OUT[k]][In[j]]=true;
          node[In[j]]++;
        }
  }//建图完毕
  for(int i=1; i<=n; i++) //拓扑排序
    if(node[i]==0)
    {
      Stack[++top]=i;
      node[i]=-1;
      deep[i]=1;
    }
  while(top)//用栈来写
  {
    x=Stack[top--];
    for(int i=1; i<=n; i++)
      if(Map[x][i] && node[i]!=-1)
      {
        node[i]--;
        deep[i]=max(deep[i],deep[x]+1);//需要注意由于拓扑排序答案不唯一，所以我们要把这句移到if外面,确保每个节点的深度都是最大深度
        if(node[i]==0)
        {
          node[i]=-1;
          Stack[++top]=i;
        }
      }
  }
  for(int i=1; i<=n; i++)
    ans=max(ans,deep[i]);
  printf("%d\n",ans);
}

